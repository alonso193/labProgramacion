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

import static java.lang.Thread.sleep;


public class secuencias extends AppCompatActivity {
    ImageView botonViolin, botonPiano, botonRedoblante, botonGuitarra, botonAcordeon, botonTrompeta;
    int contador;

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
        int i = 0;
        while(i < numSecuencias){
            final int numeroAleatorio = (int) (Math.random() * 6) + 1;
            switch (numeroAleatorio){
                case 1:
                    botonAcordeon.setImageResource(R.drawable.cuadro_negro);
                    final Handler handler1 = new Handler();
                    handler1.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            acordeonSound.start();
                        }
                    }, 10);
                    final Handler handler2 = new Handler();
                    handler2.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            botonAcordeon.setImageResource(R.drawable.acordeon);
                        }
                    }, 2000);
                    break;
                case 2:
                    botonViolin.setImageResource(R.drawable.cuadro_negro);
                    final Handler handler3 = new Handler();
                    handler3.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            violinSound.start();
                        }
                    }, 10);
                    final Handler handler4 = new Handler();
                    handler4.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            botonViolin.setImageResource(R.drawable.violin);
                        }
                    }, 2000);
                    break;
                case 3:
                    botonGuitarra.setImageResource(R.drawable.cuadro_negro);
                    final Handler handler5 = new Handler();
                    handler5.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            guitarSound.start();
                        }
                    }, 10);
                    final Handler handler6 = new Handler();
                    handler6.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            botonGuitarra.setImageResource(R.drawable.guitarra);
                        }
                    }, 2000);
                    break;
                case 4:
                    botonPiano.setImageResource(R.drawable.cuadro_negro);
                    final Handler handler7 = new Handler();
                    handler7.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            pianoSound.start();
                        }
                    }, 10);
                    final Handler handler8 = new Handler();
                    handler8.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            botonPiano.setImageResource(R.drawable.piano);
                        }
                    }, 2000);
                    break;
                case 5:
                    botonRedoblante.setImageResource(R.drawable.cuadro_negro);
                    final Handler handler9 = new Handler();
                    handler9.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            redoblanteSound.start();
                        }
                    }, 10);
                    final Handler handler10 = new Handler();
                    handler10.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            botonRedoblante.setImageResource(R.drawable.redoblante);
                        }
                    }, 2000);
                    break;
                case 6:
                    botonTrompeta.setImageResource(R.drawable.cuadro_negro);
                    final Handler handler11 = new Handler();
                    handler11.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            trompetaSound.start();
                        }
                    }, 10);
                    final Handler handler12 = new Handler();
                    handler12.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            botonTrompeta.setImageResource(R.drawable.trompeta);
                        }
                    }, 2000);
                    break;
                default:
                    break;
            }
//            if (numeroAleatorio == 1){
//                botonAcordeon.setImageResource(R.drawable.cuadro_negro);
//                final Handler handler1 = new Handler();
//                handler1.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        acordeonSound.start();
//                    }
//                }, 10);
//                final Handler handler2 = new Handler();
//                handler2.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonAcordeon.setImageResource(R.drawable.acordeon);
//                    }
//                }, 2000);
//            }
//            else if (numeroAleatorio == 2){
//                botonViolin.setImageResource(R.drawable.cuadro_negro);
//                final Handler handler3 = new Handler();
//                handler3.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        violinSound.start();
//                    }
//                }, 10);
//                final Handler handler4 = new Handler();
//                handler4.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonViolin.setImageResource(R.drawable.violin);
//                    }
//                }, 2000);
//            }
//            else if (numeroAleatorio == 3){
//                botonGuitarra.setImageResource(R.drawable.cuadro_negro);
//                final Handler handler5 = new Handler();
//                handler5.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        guitarSound.start();
//                    }
//                }, 10);
//                final Handler handler6 = new Handler();
//                handler6.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonGuitarra.setImageResource(R.drawable.guitarra);
//                    }
//                }, 2000);
//            }
//            else if (numeroAleatorio == 4){
//                botonPiano.setImageResource(R.drawable.cuadro_negro);
//                final Handler handler7 = new Handler();
//                handler7.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        pianoSound.start();
//                    }
//                }, 10);
//                final Handler handler8 = new Handler();
//                handler8.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonPiano.setImageResource(R.drawable.piano);
//                    }
//                }, 2000);
//            }
//            else if (numeroAleatorio == 5){
//                botonRedoblante.setImageResource(R.drawable.cuadro_negro);
//                final Handler handler9 = new Handler();
//                handler9.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        redoblanteSound.start();
//                    }
//                }, 10);
//                final Handler handler10 = new Handler();
//                handler10.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonRedoblante.setImageResource(R.drawable.redoblante);
//                    }
//                }, 2000);
//            }
//            else if (numeroAleatorio == 6){
//                botonTrompeta.setImageResource(R.drawable.cuadro_negro);
//                final Handler handler11 = new Handler();
//                handler11.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        trompetaSound.start();
//                    }
//                }, 10);
//                final Handler handler12 = new Handler();
//                handler12.postDelayed(new Runnable() {
//                    @Override
//                    public void run() {
//                        botonTrompeta.setImageResource(R.drawable.trompeta);
//                    }
//                }, 2000);
//            }
            i++;
        }
    }
}
