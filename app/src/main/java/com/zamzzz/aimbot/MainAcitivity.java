package com.zamzzz.aimbot;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.LinearLayout;
import android.graphics.Color;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

public class MainActivity extends Activity {

    private String copyAssetToStorage(String filename) {
        try {
            File file = new File(getFilesDir(), filename);
            if (!file.exists()) {
                InputStream is = getAssets().open(filename);
                FileOutputStream fos = new FileOutputStream(file);
                byte[] buffer = new byte[1024];
                int length;
                while ((length = is.read(buffer)) > 0) {
                    fos.write(buffer, 0, length);
                }
                fos.close();
                is.close();
            }
            return file.getAbsolutePath();
        } catch (Exception e) {
            return "";
        }
    }

    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);

        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);
        layout.setPadding(50, 50, 50, 50);
        layout.setBackgroundColor(Color.BLACK);

        TextView tv = new TextView(this);
        tv.setText("ZAMZZZ AIMBOT AUTO-PARSER");
        tv.setTextColor(Color.RED);
        tv.setTextSize(20f);
        layout.addView(tv);

        String dumpPath = copyAssetToStorage("dump.cs");
        NativeBridge.init(dumpPath);

        Switch sw = new Switch(this);
        sw.setText("AIMBOT 100% (BYPASS 6A)");
        sw.setTextColor(Color.WHITE);
        sw.setTextSize(18f);
        sw.setOnCheckedChangeListener((v, on) -> NativeBridge.setAimbot(on));
        layout.addView(sw);

        setContentView(layout);
    }
    }
