package com.example.alonso.proyectogrupal1;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import static java.lang.Math.abs;


public class MainActivity extends AppCompatActivity implements SensorEventListener {
    private SensorManager mSensorManager;
    Sensor accelerometer;
    Sensor magnetometer;
    Sensor gravity;
    private TextView text;
    private TextView text1;
    private TextView text2;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mSensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        accelerometer = mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        magnetometer = mSensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);
        gravity = mSensorManager.getDefaultSensor(Sensor.TYPE_GRAVITY);
        text = (TextView) findViewById(R.id.textWindow);
        text1 = (TextView) findViewById(R.id.textView);
        text2 = (TextView) findViewById(R.id.textView2);
    }

    protected void onResume(){
        super.onResume();
        mSensorManager.registerListener((SensorEventListener) this, accelerometer, SensorManager.SENSOR_DELAY_UI);
        mSensorManager.registerListener((SensorEventListener) this, magnetometer, SensorManager.SENSOR_DELAY_UI);
        mSensorManager.registerListener((SensorEventListener) this, gravity, SensorManager.SENSOR_DELAY_UI);
    }

    protected void onPause(){
        super.onPause();
        mSensorManager.unregisterListener((SensorEventListener) this);
    }

    public void onAccuracyChanged(Sensor sensor, int accuracy){}

    float[] mGravity;
    float[] mGeomagnetic;
    float[] mGravitySensor;
    int init_azimut = 0;
    int init_pitch = 0;
    int init_roll = 0;
    int azimut = 0;
    int pitch = 0;
    int roll = 0;
    double pi = 3.14159265359;
    float[] orientation = new float[3];
    int contador = 0;
    public void onSensorChanged(SensorEvent event){
        if (event.sensor.getType() == Sensor.TYPE_ACCELEROMETER){
            mGravity = event.values;
        }
        if (event.sensor.getType() == Sensor.TYPE_MAGNETIC_FIELD){
            mGeomagnetic = event.values;
        }
        if (mGravity != null && mGeomagnetic != null){
            float[] R = new float[9];
            float[] I = new float[9];
            boolean succes = SensorManager.getRotationMatrix(R, I, mGravity, mGeomagnetic);
            if (succes){
                float conversionGrados = (float) (180/pi);
                SensorManager.getOrientation(R, orientation);
                if (contador == 0){
                    init_azimut = (int) (orientation[0] * conversionGrados);
                    init_pitch = (int) (orientation[1] * conversionGrados);
                    init_roll = (int) (orientation[2] * conversionGrados);
                    contador++;
                }
                else{
                    azimut = (int) (orientation[0] * conversionGrados);
                    pitch = (int) (orientation[1] * conversionGrados);
                    roll = (int) (orientation[2] * conversionGrados);
                }
                String texto = Integer.toString(azimut);
                text.setText(texto);
                String texto1 = Integer.toString(pitch);
                text1.setText(texto1);
                String texto2 = Integer.toString(roll);
                text2.setText(texto2);
            }
        }
    }
}



//
//public class MainActivity extends AppCompatActivity {
//
//
//    private SensorManager sensorManager;
//    private Sensor gyroscope;
//    private Sensor magnetometer;
//    private Sensor accelerometer;
//    private SensorEventListener gyroscopeEventListener;
//    private TextView text;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
//        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
//        gyroscope = sensorManager.getDefaultSensor(Sensor.TYPE_GYROSCOPE);
//        accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
//        text = (TextView) findViewById(R.id.textWindow);
//        if (gyroscope == null){
//            Toast.makeText(this, "The device has no gyroscope sensor", Toast.LENGTH_SHORT).show();
//            finish();
//        }
//        gyroscopeEventListener = new SensorEventListener() {
//            @Override
//            public void onSensorChanged(SensorEvent event) {
//                if (event.values[2] > 1.5f){
//                    getWindow().getDecorView().setBackgroundColor(Color.BLUE);
//                    //String texto = Float.toString(event.values[2]);
//                    //text.setText(texto);
//
//                }
//                else if (event.values[2] < -1.5f){
//                    getWindow().getDecorView().setBackgroundColor(Color.YELLOW);
//                    //String texto = Float.toString(event.values[2]);
//                    //text.setText(texto);
//                }
//            }
//
//            @Override
//            public void onAccuracyChanged(Sensor sensor, int accuracy) {
//
//            }
//        };
//    }
//
//    @Override
//    protected void onResume(){
//        super.onResume();
//        sensorManager.registerListener(gyroscopeEventListener, gyroscope, SensorManager.SENSOR_DELAY_FASTEST);
//    }
//
//    @Override
//    protected void onPause(){
//        super.onPause();
//        sensorManager.unregisterListener(gyroscopeEventListener);
//    }
//}
