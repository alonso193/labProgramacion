package com.example.alonso.simon;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class botonInicio extends AppCompatActivity implements View.OnClickListener{

    Button startButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_boton_inicio);
        startButton = (Button) findViewById(R.id.buttonStart);
        startButton.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.buttonStart:
                Intent intent = new Intent(v.getContext(), secuencias.class);
                intent.putExtra("numSecuencias", 3);
                startActivityForResult(intent, 0);
                break;
        }
    }
}
