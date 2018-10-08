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
    int control = 0;
    int numeroSecuencias;
    int[] secuenciaMostrada;
    int[] secuenciaRecibida;

    final short tiempoInstrumento = 3000;

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

        numeroSecuencias = 3;


        habilitarBotones(false);
        llamadoSecuencias(numeroSecuencias);



        botonAcordeon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                acordeonSound.start();
            }
        });
        botonViolin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                violinSound.start();
            }
        });
        botonGuitarra.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                guitarSound.start();
            }
        });
        botonPiano.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                pianoSound.start();
            }
        });
        botonRedoblante.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                redoblanteSound.start();
            }
        });
        botonTrompeta.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                trompetaSound.start();
            }
        });
    }

    public void llamadoSecuencias(int numeroSecuencias){
        int numeroAleatorio = 1;
        Handler handler = new Handler();

        class InstalarSecuencia implements Runnable {
            int num;
            public InstalarSecuencia(int n) {
                num = n;
            }

            public void run() {
                desplegarSecuencias(num);
            }
        };

        for (int i = 0; i < numeroSecuencias; i++){
            numeroAleatorio = (int) (Math.random() * 6) + 1;
            final int finalNumeroAleatorio = numeroAleatorio;
            handler.postDelayed(new InstalarSecuencia(finalNumeroAleatorio), tiempoInstrumento*i);
        }
    }

    public void habilitarBotones(boolean habilitar){
        if (habilitar){
            botonAcordeon.setEnabled(true);
            botonViolin.setEnabled(true);
            botonGuitarra.setEnabled(true);
            botonPiano.setEnabled(true);
            botonRedoblante.setEnabled(true);
            botonTrompeta.setEnabled(true);
        }
        else {
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
                    botonAcordeon.setImageResource(R.drawable.acordeon);
                    control = 0;
                }
            }, 3000);
        }
        else if (numeroAleatorio == 2){
            botonViolin.setImageResource(R.drawable.cuadro_negro);
            violinSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonViolin.setImageResource(R.drawable.violin);
                    control = 0;
                }
            }, 3000);
        }
        else if (numeroAleatorio == 3){
            botonGuitarra.setImageResource(R.drawable.cuadro_negro);
            guitarSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonGuitarra.setImageResource(R.drawable.guitarra);
                    control = 0;
                }
            }, 3000);
        }
        else if (numeroAleatorio == 4){
            botonPiano.setImageResource(R.drawable.cuadro_negro);
            pianoSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonPiano.setImageResource(R.drawable.piano);
                    control = 0;
                }
            }, 3000);
        }
        else if (numeroAleatorio == 5){
            botonRedoblante.setImageResource(R.drawable.cuadro_negro);
            redoblanteSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonRedoblante.setImageResource(R.drawable.redoblante);
                    control = 0;
                }
            }, 3000);
        }
        else if (numeroAleatorio == 6){
            botonTrompeta.setImageResource(R.drawable.cuadro_negro);
            trompetaSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonTrompeta.setImageResource(R.drawable.trompeta);
                    control = 0;
                }
            }, 3000);
        }
    }


}
