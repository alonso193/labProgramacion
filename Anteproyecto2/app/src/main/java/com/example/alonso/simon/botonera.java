package com.example.alonso.simon;

import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;

import java.lang.Thread;



public class botonera extends AppCompatActivity {
    ImageButton botonViolin, botonPiano, botonRedoblante, botonGuitarra, botonAcordeon, botonTrompeta;
    MediaPlayer acordeonSound, violinSound, guitarSound, pianoSound, redoblanteSound, trompetaSound;
    int numeroSecuencias = 1;
    int secuenciasIngresadas = 0;
    int puntaje = 0;
    String secuenciaMostrada = "";
    String secuenciaRecibida = "";

    final short tiempoInstrumento = 3050;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_botonera);

        acordeonSound = MediaPlayer.create(this, R.raw.acordeon);
        violinSound = MediaPlayer.create(this, R.raw.violin);
        guitarSound = MediaPlayer.create(this, R.raw.guitarra);
        pianoSound = MediaPlayer.create(this, R.raw.piano);
        redoblanteSound = MediaPlayer.create(this, R.raw.redoblante);
        trompetaSound = MediaPlayer.create(this, R.raw.trompeta);

        botonAcordeon = (ImageButton) findViewById(R.id.acordeon);
        botonViolin = (ImageButton) findViewById(R.id.violin);
        botonGuitarra = (ImageButton) findViewById(R.id.guitarra);
        botonPiano = (ImageButton) findViewById(R.id.piano);
        botonRedoblante = (ImageButton) findViewById(R.id.redoblante);
        botonTrompeta = (ImageButton) findViewById(R.id.trompeta);


        controlFlujo();

        botonAcordeon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                acordeonSound.start();
                secuenciaRecibida += "1";
                secuenciasIngresadas++;
                if (secuenciasIngresadas == numeroSecuencias){
                    habilitarBotones(false);
                    compararSecuencias();
                }
            }
        });
        botonViolin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                violinSound.start();
                secuenciaRecibida += "2";
                secuenciasIngresadas++;
                if (secuenciasIngresadas == numeroSecuencias){
                    habilitarBotones(false);
                    compararSecuencias();
                }
            }
        });
        botonGuitarra.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                guitarSound.start();
                secuenciaRecibida += "3";
                secuenciasIngresadas++;
                if (secuenciasIngresadas == numeroSecuencias){
                    habilitarBotones(false);
                    compararSecuencias();
                }
            }
        });
        botonPiano.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                pianoSound.start();
                secuenciaRecibida += "4";
                secuenciasIngresadas++;
                if (secuenciasIngresadas == numeroSecuencias){
                    habilitarBotones(false);
                    compararSecuencias();
                }
            }
        });
        botonRedoblante.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                redoblanteSound.start();
                secuenciaRecibida += "5";
                secuenciasIngresadas++;
                if (secuenciasIngresadas == numeroSecuencias){
                    habilitarBotones(false);
                    compararSecuencias();
                }
            }
        });
        botonTrompeta.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                trompetaSound.start();
                secuenciaRecibida += "6";
                secuenciasIngresadas++;
                if (secuenciasIngresadas == numeroSecuencias){
                    habilitarBotones(false);
                    compararSecuencias();
                }
            }
        });
    }

    public void controlFlujo(){
        habilitarBotones(false);
        llamadoSecuencias(numeroSecuencias);
    }

    public void compararSecuencias(){
        boolean decision = true;
        Handler handler = new Handler();
        System.out.println("secuenciaMostrada: "+secuenciaMostrada);
        System.out.println("secuenciaRecibida: "+secuenciaRecibida);
        for (int i = 0; i < numeroSecuencias; i++){
            if (secuenciaRecibida.charAt(i) != secuenciaMostrada.charAt(i)){
                decision = false;
            }
        }
        if (decision){
            puntaje++;
            numeroSecuencias++;
            secuenciasIngresadas = 0;
            secuenciaRecibida = "";
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    controlFlujo();
                }
            },3000);
        }
        else {
            Intent intent = new Intent(this, pedirNombre.class);
            intent.putExtra("puntaje", puntaje);
            startActivityForResult(intent, 0);
        }
    }



    public void llamadoSecuencias(final int numeroSecuencias){
        habilitarBotones(false);
        int numeroAleatorio = (int) (Math.random() * 6) + 1;
        secuenciaMostrada += Integer.toString(numeroAleatorio);
        Handler handler = new Handler();
        class InstalarSecuencia implements Runnable {
            int num;
            int t;
            public InstalarSecuencia(int n, int i) {
                num = n;
                t = i;
            }

            public void run() {
                desplegarSecuencias(num);
                if (t == numeroSecuencias - 1){
                    habilitarBotones(true);
                }
            }
        };

        for (int i = 0; i < numeroSecuencias; i++){
            handler.postDelayed(new InstalarSecuencia(Integer.parseInt(Character.toString(secuenciaMostrada.charAt(i))), i),tiempoInstrumento*i);
        }
    }

    public void habilitarBotones(boolean habilitar){
        if (habilitar){
            this.setTitle("Push the bottons...");
            botonAcordeon.setEnabled(true);
            botonViolin.setEnabled(true);
            botonGuitarra.setEnabled(true);
            botonPiano.setEnabled(true);
            botonRedoblante.setEnabled(true);
            botonTrompeta.setEnabled(true);
        }
        else {
            this.setTitle("See the sequence...");
            botonAcordeon.setEnabled(false);
            botonViolin.setEnabled(false);
            botonGuitarra.setEnabled(false);
            botonPiano.setEnabled(false);
            botonRedoblante.setEnabled(false);
            botonTrompeta.setEnabled(false);
        }
    }

    public void desplegarSecuencias(int numeroAleatorio){
        Handler handler = new Handler();
        if (numeroAleatorio == 1){
            botonAcordeon.setImageResource(R.drawable.cuadro_negro);
            acordeonSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonAcordeon.setImageResource(R.drawable.acordeon_button);
                }
            }, tiempoInstrumento);
        }
        else if (numeroAleatorio == 2){
            botonViolin.setImageResource(R.drawable.cuadro_negro);
            violinSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonViolin.setImageResource(R.drawable.violin_button);
                }
            }, tiempoInstrumento);
        }
        else if (numeroAleatorio == 3){
            botonGuitarra.setImageResource(R.drawable.cuadro_negro);
            guitarSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonGuitarra.setImageResource(R.drawable.guitarra_button);
                }
            }, tiempoInstrumento);
        }
        else if (numeroAleatorio == 4){
            botonPiano.setImageResource(R.drawable.cuadro_negro);
            pianoSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonPiano.setImageResource(R.drawable.piano_button);
                }
            }, tiempoInstrumento);
        }
        else if (numeroAleatorio == 5){
            botonRedoblante.setImageResource(R.drawable.cuadro_negro);
            redoblanteSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonRedoblante.setImageResource(R.drawable.redoblante_button);
                }
            }, tiempoInstrumento);
        }
        else if (numeroAleatorio == 6){
            botonTrompeta.setImageResource(R.drawable.cuadro_negro);
            trompetaSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonTrompeta.setImageResource(R.drawable.trompeta_button);
                }
            }, tiempoInstrumento);
        }
    }
}
