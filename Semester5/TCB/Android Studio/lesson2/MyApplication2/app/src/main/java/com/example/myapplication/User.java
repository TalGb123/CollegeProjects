package com.example.myapplication;

import android.os.Parcel;
import android.os.Parcelable;

public class User implements Parcelable {
    private String username;
    private String password;
    private boolean rememberMe;
    private int likePressable;

    // Constructor used in MainActivity
    public User(String username, String password, boolean rememberMe, int likePressable) {
        this.username = username;
        this.password = password;
        this.rememberMe = rememberMe;
        this.likePressable = likePressable;
    }

    protected User(Parcel in) {
        username = in.readString();
        password = in.readString();
        rememberMe = in.readByte() != 0;
        likePressable = in.readInt();
    }

    public static final Creator<User> CREATOR = new Creator<User>() {
        @Override
        public User createFromParcel(Parcel in) {
            return new User(in);
        }

        @Override
        public User[] newArray(int size) {
            return new User[size];
        }
    };

    @Override
    public int describeContents() { return 0; }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(username);
        dest.writeString(password);
        dest.writeByte((byte) (rememberMe ? 1 : 0));
        dest.writeInt(likePressable);
    }

    // Getters - Ensure these names match your Activity calls!
    public String getUsername() { return username; }
    public String getPassword() { return password; }
    public boolean isRememberMe() { return rememberMe; }
    public int getLikePressable() { return likePressable; }
}