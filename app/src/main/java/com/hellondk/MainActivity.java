package com.hellondk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView tvResult;
    private EditText etNumber;
    private Button btnCalculate;

    // Used to load the 'native-lib' library on application startup.
    // The libname argument must not contain any platform specific prefix, file extension or path
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tvResult = findViewById(R.id.tvResult);
        etNumber = findViewById(R.id.etNumber);
        btnCalculate = findViewById(R.id.btnCalculate);

        btnCalculate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (etNumber.getText().toString() != null) {
                    int input = Integer.parseInt(etNumber.getText().toString());
                    tvResult.setText(findPrime(input));
                }
            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    // Native method must be declared in JAVA
    // The native method is simply declared with the native keyword, and no implementation is provided in Java
    // Native method can be public, private, package or protected
    // native keyword denote that this method is implemented in other language
    // native methods don’t have to be static methods, and don’t have to use primitive types only
    public native String getPrimeNumber();

    public native String findPrime(int number);
}
