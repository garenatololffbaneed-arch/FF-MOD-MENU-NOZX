package com.zamzzz.aimbot;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.LinearLayout;
import android.graphics.Color;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);

        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);
        layout.setPadding(50, 50, 50, 50);
        layout.setBackgroundColor(Color.BLACK);

        TextView tv = new TextView(this);
        tv.setText("ZAMZZZ AIMBOT (TEST BUILD)");
        tv.setTextColor(Color.RED);
        tv.setTextSize(20f);
        layout.addView(tv);

        // Sementara gak manggil file dump dulu biar gak crash
        // NativeBridge.init(""); 

        Switch sw = new Switch(this);
        sw.setText("AIMBOT 100% (BYPASS 6A)");
        sw.setTextColor(Color.WHITE);
        sw.setTextSize(18f);
        sw.setOnCheckedChangeListener((v, on) -> NativeBridge.setAimbot(on));
        layout.addView(sw);

        setContentView(layout);
    }
            }
