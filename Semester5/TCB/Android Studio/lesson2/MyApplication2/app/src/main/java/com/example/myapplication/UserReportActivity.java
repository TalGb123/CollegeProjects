package com.example.myapplication;
import android.os.Bundle;

import android.widget.TextView;
import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class UserReportActivity extends AppCompatActivity {
    TextView textUsername;
    TextView textPassword;
    TextView textRememberMe;
    TextView textLikePressable;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_user_report);

        User user = getIntent().getParcelableExtra("USER_OBJECT");

        if (user == null) {
            finish();
            return;
        }

        textUsername = findViewById(R.id.usernameData);
        textPassword = findViewById(R.id.passwordData);
        textRememberMe = findViewById(R.id.rememberMeData);
        textLikePressable = findViewById(R.id.likePressData);

        // if (user.isRememberMe())
        //     textRememberMe.setText("Remember Me");
        // else
        //     textRememberMe.setText("Not Remember Me");

        textUsername.setText(user.getUsername());
        textPassword.setText(user.getPassword());
        textRememberMe.setText(String.valueOf(user.isRememberMe()));
        textLikePressable.setText(String.valueOf(user.getLikePressable()));
    }
}
