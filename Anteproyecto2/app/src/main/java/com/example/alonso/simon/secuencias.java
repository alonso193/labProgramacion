package com.example.alonso.simon;

import android.annotation.TargetApi;
import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.media.MediaPlayer;
import android.os.Build;
import android.os.Handler;
import android.support.annotation.RequiresApi;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import java.util.concurrent.TimeUnit;

import static java.lang.Thread.currentThread;
import static java.lang.Thread.sleep;


public class secuencias extends AppCompatActivity {
    ImageView botonViolin, botonPiano, botonRedoblante, botonGuitarra, botonAcordeon, botonTrompeta;
    int contador = 0;
    int control = 0;

    @TargetApi(Build.VERSION_CODES.JELLY_BEAN)
    @RequiresApi(api = Build.VERSION_CODES.JELLY_BEAN)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_secuencias);


        int numSecuencias = 0;
        Intent parametroRecibido = getIntent();
        Bundle bundle = parametroRecibido.getExtras();
        if (bundle != null){
            numSecuencias = (int) bundle.get("numSecuencias");
        }
        int[] arregloSecuencias = new int[numSecuencias];
        final MediaPlayer violinSound = MediaPlayer.create(this, R.raw.violin);
        final MediaPlayer guitarSound = MediaPlayer.create(this, R.raw.guitarra);
        final MediaPlayer redoblanteSound = MediaPlayer.create(this, R.raw.redoblante);
        final MediaPlayer trompetaSound = MediaPlayer.create(this, R.raw.trompeta);
        final MediaPlayer acordeonSound = MediaPlayer.create(this, R.raw.acordeon);
        final MediaPlayer pianoSound = MediaPlayer.create(this, R.raw.piano);
        botonAcordeon = (ImageView) findViewById(R.id.acordeon);
        botonViolin = (ImageView) findViewById(R.id.violin);
        botonGuitarra = (ImageView) findViewById(R.id.guitarra);
        botonPiano = (ImageView) findViewById(R.id.piano);
        botonRedoblante = (ImageView) findViewById(R.id.redoblante);
        botonTrompeta = (ImageView) findViewById(R.id.trompeta);
        for(int i = 0; i < numSecuencias; i++) {
            final int numeroAleatorio = (int) (Math.random() * 6) + 1;
            final Handler handler = new Handler();
            if (numeroAleatorio == 1) {
                for (int j = 1; j < 4; j++) {
                    final int parametro = i;
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            acciones(acordeonSound, parametro, numeroAleatorio);
                        }
                    }, 1);
                }
            } else if (numeroAleatorio == 2) {
                for (int j = 1; j < 4; j++) {
                    final int parametro = i;
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            acciones(violinSound, parametro, numeroAleatorio);
                        }
                    }, 1);
                }
            } else if (numeroAleatorio == 3) {
                for (int j = 1; j < 4; j++) {
                    final int parametro = i;
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            acciones(guitarSound, parametro, numeroAleatorio);
                        }
                    }, 1);
                }
            } else if (numeroAleatorio == 4) {
                for (int j = 1; j < 4; j++) {
                    final int parametro = i;
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            acciones(pianoSound, parametro, numeroAleatorio);
                        }
                    }, 1);
                }
            } else if (numeroAleatorio == 5) {
                for (int j = 1; j < 4; j++) {
                    final int parametro = i;
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            acciones(redoblanteSound, parametro, numeroAleatorio);
                        }
                    }, 1);
                }
            } else if (numeroAleatorio == 6) {
                for (int j = 1; j < 4; j++) {
                    final int parametro = i;
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            acciones(trompetaSound, parametro, numeroAleatorio);
                        }
                    }, 1);
                }
            }
        }



//            final Handler handler1 = new Handler();
//            if (numeroAleatorio == 1){
//                botonAcordeon.setImageResource(R.drawable.cuadro_negro);
//                //acordeonSound.start();
//                handler1.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonAcordeon.setImageResource(R.drawable.acordeon);
//                    }
//                }, 3000);
//
//            }
//            else if (numeroAleatorio == 2){
//                botonViolin.setImageResource(R.drawable.cuadro_negro);
//                //violinSound.start();
//                handler1.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonViolin.setImageResource(R.drawable.violin);
//                    }
//                }, 3000);
//
//            }
//            else if (numeroAleatorio == 3){
//                botonGuitarra.setImageResource(R.drawable.cuadro_negro);
//                //guitarSound.start();
//                handler1.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonGuitarra.setImageResource(R.drawable.guitarra);
//                    }
//                }, 3000);
//
//            }
//            else if (numeroAleatorio == 4){
//                botonPiano.setImageResource(R.drawable.cuadro_negro);
//                //pianoSound.start();
//                handler1.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonPiano.setImageResource(R.drawable.piano);
//                    }
//                }, 3000);
//
//            }
//            else if (numeroAleatorio == 5){
//                botonRedoblante.setImageResource(R.drawable.cuadro_negro);
//                //redoblanteSound.start();
//                handler1.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonRedoblante.setImageResource(R.drawable.redoblante);
//                    }
//                }, 3000);
//
//            }
//            else if (numeroAleatorio == 6){
//                botonTrompeta.setImageResource(R.drawable.cuadro_negro);
//                //trompetaSound.start();
//                handler1.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonTrompeta.setImageResource(R.drawable.trompeta);
//                    }
//                }, 3000);
//
//            }

    }

    private void acciones(MediaPlayer sonido, int j, int numeroAleatorio) {
        if(contador == 1){
            if (control == 1){
                botonAcordeon.setImageResource(R.drawable.cuadro_negro);
            }
            else if (control == 2){
                botonViolin.setImageResource(R.drawable.cuadro_negro);
            }
            else if (control == 3){
                botonGuitarra.setImageResource(R.drawable.cuadro_negro);
            }
            else if (control == 4){
                botonPiano.setImageResource(R.drawable.cuadro_negro);
            }
            else if (control == 5){
                botonRedoblante.setImageResource(R.drawable.cuadro_negro);
            }
            else if (control == 6){
                botonTrompeta.setImageResource(R.drawable.cuadro_negro);
            }
        }
        else if (contador == 2){
            if (control == 1){
                sonido.start();
            }
            else if (control == 2){
                sonido.start();
            }
            else if (control == 3){
                sonido.start();
            }
            else if (control == 4){
                sonido.start();
            }
            else if (control == 5){
                sonido.start();
            }
            else if (control == 6){
                sonido.start();
            }
        }
        else if (contador == 3){
            if (control == 1){
                botonAcordeon.setImageResource(R.drawable.acordeon);
            }
            else if (control == 2){
                botonViolin.setImageResource(R.drawable.violin);
            }
            else if (control == 3){
                botonGuitarra.setImageResource(R.drawable.guitarra);
            }
            else if (control == 4){
                botonPiano.setImageResource(R.drawable.piano);
            }
            else if (control == 5){
                botonRedoblante.setImageResource(R.drawable.redoblante);
            }
            else if (control == 6){
                botonTrompeta.setImageResource(R.drawable.trompeta);
            }
        }
    }
}
