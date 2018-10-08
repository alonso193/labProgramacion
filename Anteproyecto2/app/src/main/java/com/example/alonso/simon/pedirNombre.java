package com.example.alonso.simon;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class pedirNombre extends AppCompatActivity {
    EditText textoIngresado;
    Button botonSave;
    int puntaje;
    String usuario = "";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pedir_nombre);

        textoIngresado = (EditText) findViewById(R.id.plain_text_input);
        botonSave = (Button) findViewById(R.id.botonSave);

        Intent parametroRecibido = getIntent();
        Bundle bundle = parametroRecibido.getExtras();
        if (bundle != null) {
            puntaje = (int) bundle.get("puntaje");
        }
        usuario = textoIngresado.getText().toString();

        botonSave.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(v.getContext(), mostrarHighScores.class);
                intent.putExtra("puntaje", puntaje);
                intent.putExtra("usuario", usuario);
                startActivityForResult(intent, 0);
            }
        });



    }
}
