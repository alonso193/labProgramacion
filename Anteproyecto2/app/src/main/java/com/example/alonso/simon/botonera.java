package com.example.alonso.simon;

import android.content.Intent;
import android.media.MediaPlayer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;

public class botonera extends AppCompatActivity {
    ImageButton botonViolin, botonPiano, botonRedoblante, botonGuitarra, botonAcordeon, botonTrompeta;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_botonera);
        final MediaPlayer violinSound = MediaPlayer.create(this, R.raw.violin);
        final MediaPlayer guitarSound = MediaPlayer.create(this, R.raw.guitarra);
        final MediaPlayer redoblanteSound = MediaPlayer.create(this, R.raw.redoblante);
        final MediaPlayer trompetaSound = MediaPlayer.create(this, R.raw.trompeta);
        final MediaPlayer acordeonSound = MediaPlayer.create(this, R.raw.acordeon);
        final MediaPlayer pianoSound = MediaPlayer.create(this, R.raw.piano);
        botonAcordeon = (ImageButton) findViewById(R.id.acordeon);
        botonViolin = (ImageButton) findViewById(R.id.violin);
        botonGuitarra = (ImageButton) findViewById(R.id.guitarra);
        botonPiano = (ImageButton) findViewById(R.id.piano);
        botonRedoblante = (ImageButton) findViewById(R.id.redoblante);
        botonTrompeta = (ImageButton) findViewById(R.id.trompeta);

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


}
