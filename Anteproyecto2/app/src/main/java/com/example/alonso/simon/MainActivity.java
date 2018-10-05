package com.example.alonso.simon;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    TextView mainMText;
    Button botonPlay, botonHighScores;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mainMText = (TextView) findViewById(R.id.main_menu_text);
        botonPlay = (Button) findViewById(R.id.botonPlay);
        botonHighScores = (Button) findViewById(R.id.botonHighScores);
        botonPlay.setOnClickListener(this);
        botonHighScores.setOnClickListener(this);

    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.botonPlay:
                Intent intent = new Intent(v.getContext(), botonInicio.class);
                startActivityForResult(intent, 0);
                break;
            case R.id.botonHighScores:
                break;
            default:
                break;
        }
    }
}
