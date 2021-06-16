xof 0303txt 0032
template FVFData {
 <b6e70a0e-8ef9-4e83-94ad-ecc8b0c04897>
 DWORD dwFVF;
 DWORD nDWords;
 array DWORD data[nDWords];
}

template EffectInstance {
 <e331f7e4-0559-4cc2-8e99-1cec1657928f>
 STRING EffectFilename;
 [...]
}

template EffectParamFloats {
 <3014b9a0-62f5-478c-9b86-e4ac9f4e418b>
 STRING ParamName;
 DWORD nFloats;
 array FLOAT Floats[nFloats];
}

template EffectParamString {
 <1dbc4c88-94c1-46ee-9076-2c28818c9481>
 STRING ParamName;
 STRING Value;
}

template EffectParamDWord {
 <e13963bc-ae51-4c5d-b00f-cfa3a9d97ce5>
 STRING ParamName;
 DWORD Value;
}


Mesh Box01 {
 36;
 -24.070889;0.000000;8.311082;,
 0.033939;0.000000;8.311082;,
 -24.070889;0.000000;-8.021018;,
 0.033939;0.000000;-8.021018;,
 -24.070889;0.000000;-8.021018;,
 0.033939;0.000000;8.311082;,
 0.033939;-0.861186;-8.021018;,
 0.033939;-0.861186;8.311082;,
 -24.070889;-0.861186;-8.021018;,
 -24.070889;-0.861186;8.311082;,
 -24.070889;-0.861186;-8.021018;,
 0.033939;-0.861186;8.311082;,
 0.033939;0.000000;-8.021018;,
 0.033939;-0.861186;-8.021018;,
 -24.070889;0.000000;-8.021018;,
 -24.070889;-0.861186;-8.021018;,
 -24.070889;0.000000;-8.021018;,
 0.033939;-0.861186;-8.021018;,
 0.033939;0.000000;8.311082;,
 0.033939;-0.861186;8.311082;,
 0.033939;0.000000;-8.021018;,
 0.033939;-0.861186;-8.021018;,
 0.033939;0.000000;-8.021018;,
 0.033939;-0.861186;8.311082;,
 -24.070889;0.000000;8.311082;,
 -24.070889;-0.861186;8.311082;,
 0.033939;0.000000;8.311082;,
 0.033939;-0.861186;8.311082;,
 0.033939;0.000000;8.311082;,
 -24.070889;-0.861186;8.311082;,
 -24.070889;0.000000;-8.021018;,
 -24.070889;-0.861186;-8.021018;,
 -24.070889;0.000000;8.311082;,
 -24.070889;-0.861186;8.311082;,
 -24.070889;0.000000;8.311082;,
 -24.070889;-0.861186;-8.021018;;
 12;
 3;0,1,2;,
 3;3,4,5;,
 3;6,7,8;,
 3;9,10,11;,
 3;12,13,14;,
 3;15,16,17;,
 3;18,19,20;,
 3;21,22,23;,
 3;24,25,26;,
 3;27,28,29;,
 3;30,31,32;,
 3;33,34,35;;

 MeshNormals  {
  36;
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;;
  12;
  3;0,1,2;,
  3;3,4,5;,
  3;6,7,8;,
  3;9,10,11;,
  3;12,13,14;,
  3;15,16,17;,
  3;18,19,20;,
  3;21,22,23;,
  3;24,25,26;,
  3;27,28,29;,
  3;30,31,32;,
  3;33,34,35;;
 }

 MeshMaterialList  {
  1;
  12;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;

  Material Standard_9 {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;

   EffectInstance {
    "C:\\Work\\AdvancedDecals\\data\\scene.fx";

    EffectParamString {
     "g_tNormal";
     "style_06_brickwall_01_tgspace.png";
    }

    EffectParamString {
     "g_tDiffuse";
     "style_06_brickwall_01_diffuse.png";
    }

    EffectParamString {
     "g_tSpecular";
     "style_06_brickwall_01_gloss.png";
    }

    EffectParamString {
     "g_tOpacity";
     "None";
    }

    EffectParamDWord {
     "technique";
     0;
    }
   }
  }
 }

 MeshTextureCoords  {
  36;
  -0.705241;-0.316605;,
  1.705242;-0.316605;,
  -0.705242;1.316605;,
  1.705241;1.316605;,
  -0.705242;1.316605;,
  1.705242;-0.316605;,
  -0.705241;1.316605;,
  -0.705242;-0.316605;,
  1.705242;1.316605;,
  1.705241;-0.316605;,
  1.705242;1.316605;,
  -0.705242;-0.316605;,
  1.705241;0.863149;,
  1.705241;0.949267;,
  -0.705242;0.863149;,
  -0.705242;0.949267;,
  -0.705242;0.863149;,
  1.705241;0.949267;,
  1.316605;0.863149;,
  1.316605;0.949267;,
  -0.316605;0.863149;,
  -0.316605;0.949267;,
  -0.316605;0.863149;,
  1.316605;0.949267;,
  1.705241;0.863149;,
  1.705241;0.949267;,
  -0.705242;0.863149;,
  -0.705242;0.949267;,
  -0.705242;0.863149;,
  1.705241;0.949267;,
  1.316605;0.863149;,
  1.316605;0.949267;,
  -0.316605;0.863149;,
  -0.316605;0.949267;,
  -0.316605;0.863149;,
  1.316605;0.949267;;
 }
}

Mesh Box02 {
 36;
 -20.259018;0.000000;0.022493;,
 -4.047243;0.000000;4.233274;,
 -20.259018;0.000000;4.233274;,
 -4.047243;0.000000;4.233274;,
 -20.259018;0.000000;0.022493;,
 -4.047243;0.000000;0.022493;,
 -20.259018;8.124158;0.022493;,
 -4.047243;8.124158;4.233274;,
 -4.047243;8.124158;0.022493;,
 -4.047243;8.124158;4.233274;,
 -20.259018;8.124158;0.022493;,
 -20.259018;8.124158;4.233274;,
 -20.259018;0.000000;0.022493;,
 -4.047243;8.124158;0.022493;,
 -4.047243;0.000000;0.022493;,
 -4.047243;8.124158;0.022493;,
 -20.259018;0.000000;0.022493;,
 -20.259018;8.124158;0.022493;,
 -4.047243;0.000000;0.022493;,
 -4.047243;8.124158;4.233274;,
 -4.047243;0.000000;4.233274;,
 -4.047243;8.124158;4.233274;,
 -4.047243;0.000000;0.022493;,
 -4.047243;8.124158;0.022493;,
 -4.047243;0.000000;4.233274;,
 -20.259018;8.124158;4.233274;,
 -20.259018;0.000000;4.233274;,
 -20.259018;8.124158;4.233274;,
 -4.047243;0.000000;4.233274;,
 -4.047243;8.124158;4.233274;,
 -20.259018;0.000000;4.233274;,
 -20.259018;8.124158;0.022493;,
 -20.259018;0.000000;0.022493;,
 -20.259018;8.124158;0.022493;,
 -20.259018;0.000000;4.233274;,
 -20.259018;8.124158;4.233274;;
 12;
 3;0,1,2;,
 3;3,4,5;,
 3;6,7,8;,
 3;9,10,11;,
 3;12,13,14;,
 3;15,16,17;,
 3;18,19,20;,
 3;21,22,23;,
 3;24,25,26;,
 3;27,28,29;,
 3;30,31,32;,
 3;33,34,35;;

 MeshNormals  {
  36;
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;;
  12;
  3;0,1,2;,
  3;3,4,5;,
  3;6,7,8;,
  3;9,10,11;,
  3;12,13,14;,
  3;15,16,17;,
  3;18,19,20;,
  3;21,22,23;,
  3;24,25,26;,
  3;27,28,29;,
  3;30,31,32;,
  3;33,34,35;;
 }

 MeshMaterialList  {
  1;
  12;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;

  Material Standard_8 {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;

   EffectInstance {
    "C:\\Work\\AdvancedDecals\\data\\scene.fx";

    EffectParamString {
     "g_tNormal";
     "style_01_surface_01_tgspace.png";
    }

    EffectParamString {
     "g_tDiffuse";
     "style_01_surface_01_diffuse.png";
    }

    EffectParamString {
     "g_tSpecular";
     "style_01_surface_01_gloss.png";
    }

    EffectParamString {
     "g_tOpacity";
     "None";
    }

    EffectParamDWord {
     "technique";
     0;
    }
   }
  }
 }

 MeshTextureCoords  {
  36;
  1.324054;0.512254;,
  -0.297123;0.091176;,
  1.324054;0.091176;,
  -0.297123;0.091176;,
  1.324054;0.512254;,
  -0.297123;0.512254;,
  -0.324054;0.512254;,
  1.297123;0.091176;,
  1.297123;0.512254;,
  1.297123;0.091176;,
  -0.324054;0.512254;,
  -0.324054;0.091176;,
  -0.324054;0.863149;,
  1.297123;0.050733;,
  1.297123;0.863149;,
  1.297123;0.050733;,
  -0.324054;0.863149;,
  -0.324054;0.050733;,
  0.487746;0.863149;,
  0.908824;0.050733;,
  0.908824;0.863149;,
  0.908824;0.050733;,
  0.487746;0.863149;,
  0.487746;0.050733;,
  -0.297123;0.863149;,
  1.324054;0.050733;,
  1.324054;0.863149;,
  1.324054;0.050733;,
  -0.297123;0.863149;,
  -0.297123;0.050733;,
  0.091176;0.863149;,
  0.512254;0.050733;,
  0.512254;0.863149;,
  0.512254;0.050733;,
  0.091176;0.863149;,
  0.091176;0.050733;;
 }
}