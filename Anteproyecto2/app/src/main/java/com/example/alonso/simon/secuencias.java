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

        final Intent intent = new Intent(this, botonera.class);

        int numAleatorio = 0;
        Intent parametroRecibido = getIntent();
        Bundle bundle = parametroRecibido.getExtras();
        if (bundle != null) {
            numAleatorio = (int) bundle.get("numAleatorio");
        }

        final MediaPlayer acordeonSound = MediaPlayer.create(this, R.raw.acordeon);
        final MediaPlayer violinSound = MediaPlayer.create(this, R.raw.violin);
        final MediaPlayer guitarSound = MediaPlayer.create(this, R.raw.guitarra);
        final MediaPlayer pianoSound = MediaPlayer.create(this, R.raw.piano);
        final MediaPlayer redoblanteSound = MediaPlayer.create(this, R.raw.redoblante);
        final MediaPlayer trompetaSound = MediaPlayer.create(this, R.raw.trompeta);

        botonAcordeon = (ImageView) findViewById(R.id.acordeon);
        botonViolin = (ImageView) findViewById(R.id.violin);
        botonGuitarra = (ImageView) findViewById(R.id.guitarra);
        botonPiano = (ImageView) findViewById(R.id.piano);
        botonRedoblante = (ImageView) findViewById(R.id.redoblante);
        botonTrompeta = (ImageView) findViewById(R.id.trompeta);
        Handler handler = new Handler();
        if (numAleatorio == 1){
            botonAcordeon.setImageResource(R.drawable.cuadro_negro);
            acordeonSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonAcordeon.setImageResource(R.drawable.acordeon);
                    intent.putExtra("instrumentoSonado", 1);
                    startActivityForResult(intent, 0);
                }
            }, 3000);
        }
        else if (numAleatorio == 2){
            botonViolin.setImageResource(R.drawable.cuadro_negro);
            violinSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonViolin.setImageResource(R.drawable.violin);
                    intent.putExtra("instrumentoSonado", 2);
                    startActivityForResult(intent, 0);
                }
            }, 3000);
        }
        else if (numAleatorio == 3){
            botonGuitarra.setImageResource(R.drawable.cuadro_negro);
            guitarSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonGuitarra.setImageResource(R.drawable.guitarra);
                    intent.putExtra("instrumentoSonado", 3);
                    startActivityForResult(intent, 0);
                }
            }, 3000);
        }
        else if (numAleatorio == 4){
            botonPiano.setImageResource(R.drawable.cuadro_negro);
            pianoSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonPiano.setImageResource(R.drawable.piano);
                    intent.putExtra("instrumentoSonado", 4);
                    startActivityForResult(intent, 0);
                }
            }, 3000);
        }
        else if (numAleatorio == 5){
            botonRedoblante.setImageResource(R.drawable.cuadro_negro);
            redoblanteSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonRedoblante.setImageResource(R.drawable.redoblante);
                    intent.putExtra("instrumentoSonado", 5);
                    startActivityForResult(intent, 0);
                }
            }, 3000);
        }
        else if (numAleatorio == 6){
            botonTrompeta.setImageResource(R.drawable.cuadro_negro);
            trompetaSound.start();
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    botonTrompeta.setImageResource(R.drawable.trompeta);
                    intent.putExtra("instrumentoSonado", 5);
                    startActivityForResult(intent, 0);
                }
            }, 3000);
        }
    }
}

