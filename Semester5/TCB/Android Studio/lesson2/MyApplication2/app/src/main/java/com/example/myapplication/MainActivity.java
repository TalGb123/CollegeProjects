package com.example.myapplication;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    // 1. Variable Declarations
    EditText username, password;
    CheckBox checkBoxRememberMe;
    Button loginButton;
    View likePressable;
    TextView likeTextView;
    int likeCount = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        // 2. Initializing UI Elements
        username = findViewById(R.id.username);
        password = findViewById(R.id.password);
        checkBoxRememberMe = findViewById(R.id.checkBoxRememberMe);
        loginButton = findViewById(R.id.loginButton);
        likePressable = findViewById(R.id.LikePressable);
        likeTextView = findViewById(R.id.LikeTextView);

        // 3. Like Button Logic
        likePressable.setOnClickListener(view -> {
            likeCount++;
            // Update the text on screen so you can see the count change
            if (likeTextView != null) {
                likeTextView.setText("Likes: " + likeCount);
            }
            Toast.makeText(this, "Liked! Total: " + likeCount, Toast.LENGTH_SHORT).show();
        });

        // 4. Login Button Logic
        loginButton.setOnClickListener(view -> {
            String usernameText = username.getText().toString();
            String passwordText = password.getText().toString().trim();

            // Validation logic
            if (usernameText.isEmpty() || passwordText.isEmpty()) {
                Toast.makeText(this, "Username or Password cannot be empty", Toast.LENGTH_SHORT).show();
                return;
            }

            if (passwordText.length() < 8) {
                Toast.makeText(this, "Password must be at least 8 characters", Toast.LENGTH_SHORT).show();
                return;
            }

            boolean rememberMe = checkBoxRememberMe.isChecked();

            // 5. Creating User object and starting the Report Activity
            User user = new User(usernameText, passwordText, rememberMe, likeCount);
            Intent startUserReportActivity = new Intent(this, UserReportActivity.class);

            startUserReportActivity.putExtra("USER_OBJECT", user);
            startActivity(startUserReportActivity);
        });
    }
}