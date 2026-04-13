package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private EditText etNum1, etNum2;
    private Spinner spinnerOps;
    private Button btnCalculate;
    private TextView tvResult;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etNum1 = findViewById(R.id.etNum1);
        etNum2 = findViewById(R.id.etNum2);
        spinnerOps = findViewById(R.id.spinnerOps);
        btnCalculate = findViewById(R.id.btnCalculate);
        tvResult = findViewById(R.id.tvResult);

        btnCalculate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) { calculate(); }
        });
    }

    private void calculate() {
        try {
            String s1 = etNum1.getText().toString();
            String s2 = etNum2.getText().toString();

            if (s1.isEmpty() || s2.isEmpty()) {
                Toast.makeText(this, "Please enter both numbers", Toast.LENGTH_SHORT).show();
                return;
            }

            double n1 = Double.parseDouble(s1);
            double n2 = Double.parseDouble(s2);
            double result = 0;

            String operation = spinnerOps.getSelectedItem().toString();

            switch (operation) {
                case "Addition (+)":
                    result = n1 + n2;
                    break;
                case "Subtraction (-)":
                    result = n1 - n2;
                    break;
                case "Multiplication (*)":
                    result = n1 * n2;
                    break;
                case "Division (/)":
                    if (n2 == 0) {
                        tvResult.setText("Error: Cannot divide by zero");
                        return;
                    }
                    result = n1 / n2;
                    break;
                case "Power (^)":
                    result = Math.pow(n1, n2);
                    break;
            }

            if (result % 1 == 0) {
                tvResult.setText("Result: " + ((int)result));
            }
            else {
                tvResult.setText("Result: " + result);
            }

        }
        catch (Exception e) {
            tvResult.setText("Error in calculation");
            Toast.makeText(this, "An error occurred", Toast.LENGTH_SHORT).show();
        }
    }
}