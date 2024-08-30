/*
   Repo:  https://github.com/aos92/ESP32-Kalkulator-Nutrisi-AB-Mix-Hidroponik
   Simulasi: https://wokwi.com/projects/407626959875425281
   Sumber: https://scienceinhydroponics.com
*/


#include <Arduino.h>

// Variabel global
float Volume_Air = 0.0;

// Kelompok NPK
float Dosis_NPK = 0.0;
float NPK_N = 0.0;
float NPK_P = 0.0;
float NPK_K = 0.0;
float NPK_N_PPM = 0.0;
float NPK_P_PPM = 0.0;
float NPK_K_PPM = 0.0;

// Kelompok KNO3
float Dosis_KNO3 = 0.0;
float KNO3_N = 0.0;
float KNO3_K = 0.0;
float KNO3_N_PPM = 0.0;
float KNO3_K_PPM = 0.0;

// Kelompok MgSO4
float Dosis_MgSO4 = 0.0;
float MgSO4_Mg = 0.0;
float MgSO4_S = 0.0;
float MgSO4_Mg_PPM = 0.0;
float MgSO4_S_PPM = 0.0;

// Kelompok NH4H2PO4
float Dosis_NH4H2PO4 = 0.0;
float NH4H2PO4_N = 0.0;
float NH4H2PO4_P = 0.0;
float NH4H2PO4_N_PPM = 0.0;
float NH4H2PO4_P_PPM = 0.0;

// Kelompok CaNO3
float Dosis_CaNO32 = 0.0;
float CaNO32_N = 0.0;
float CaNO32_Ca = 0.0;
float CaNO32_N_PPM = 0.0;
float CaNO32_Ca_PPM = 0.0;

// Kelompok Konsentrasi dan Estimasi
float Pre_Solusi_Stok_A = 0.0;
float Final_Larutan_Solusi_Stok_A = 0.0;
float Pre_Konsentrasi_Stok_A = 0.0;
float Final_Larutan_Konsentrasi_Stok_A = 0.0;
float Estimasi_Vol_A = 0.0;

float Pre_Solusi_Stok_B = 0.0;
float Final_Larutan_Solusi_Stok_B = 0.0;
float Pre_Konsentrasi_Stok_B = 0.0;
float Final_Larutan_Konsentrasi_Stok_B = 0.0;
float Estimasi_Vol_B = 0.0;

String DataDiterima = "", semuaPerintah = "", perintah = "", str1 = "", str2 = "", str3 = "", str4 = "", str5 = "", str6 = "", str7 = "", str8 = "", str9 = "";

void dapatPerintah() {
  DataDiterima = ""; semuaPerintah = ""; perintah = ""; str1 = ""; str2 = ""; str3 = ""; str4 = ""; str5 = ""; str6 = ""; str7 = ""; str8 = ""; str9 = "";
  byte StatusPenerimaan = 0, StatusPerintah = 1, StatusString = 1, StatusTanya = 0, StatusSamaDengan = 0, StatusTitikKoma = 0;

  if (Serial.available()) {
    while (Serial.available()) {
      char c = Serial.read();
      DataDiterima += String(c);

      if (c == '?') StatusPenerimaan = 1;
      if ((c == ' ') || (c == '\r') || (c == '\n')) StatusPenerimaan = 0;

      if (StatusPenerimaan == 1) {
        semuaPerintah += String(c);

        if (c == '=') StatusPerintah = 0;
        if (c == ';') StatusString++;
        if ((StatusPerintah == 1) && ((c != '?') || (StatusTanya == 1))) perintah += String(c);
        if ((StatusPerintah == 0) && (StatusString == 1) && ((c != '=') || (StatusSamaDengan == 1))) str1 += String(c);
        if ((StatusPerintah == 0) && (StatusString == 2) && (c != ';')) str2 += String(c);
        if ((StatusPerintah == 0) && (StatusString == 3) && (c != ';')) str3 += String(c);
        if ((StatusPerintah == 0) && (StatusString == 4) && (c != ';')) str4 += String(c);
        if ((StatusPerintah == 0) && (StatusString == 5) && (c != ';')) str5 += String(c);
        if ((StatusPerintah == 0) && (StatusString == 6) && (c != ';')) str6 += String(c);
        if ((StatusPerintah == 0) && (StatusString == 7) && (c != ';')) str7 += String(c);
        if ((StatusPerintah == 0) && (StatusString == 8) && (c != ';')) str8 += String(c);
        if ((StatusPerintah == 0) && (StatusString >= 9) && ((c != ';') || (StatusTitikKoma == 1))) str9 += String(c);

        if (c == '?') StatusTanya = 1;
        if (c == '=') StatusSamaDengan = 1;
        if ((StatusString >= 9) && (c == ';')) StatusTitikKoma = 1;
      }
      delay(1);
    }
  }
}

bool validFloat(const String& str) {
  char* end;
  str.toFloat();
  return (str.toDouble() != strtod(str.c_str(), &end) || *end != '\0') ? false : true;
}

void eksekusiPerintah() {
  Serial.println("");
  Serial.println("Data Diterima: " + DataDiterima);
  Serial.println("perintah= " + perintah + " ,str1= " + str1 + " ,str2= " + str2 + " ,str3= " + str3 + " ,str4= " + str4 + " ,str5= " + str5 + " ,str6= " + str6 + " ,str7= " + str7 + " ,str8= " + str8 + " ,str9= " + str9);
  Serial.println("");

  if (perintah == "volair") {
    if (validFloat(str1)) {
      Volume_Air = str1.toFloat();
      Serial.print("Volume Air diatur ke: ");
      Serial.println(Volume_Air);
    } else {
      Serial.println("Ops. Input untuk Volume Air tidak valid.");
    }
  } else if (perintah == "npk") {
    if (validFloat(str1) && validFloat(str2) && validFloat(str3) && validFloat(str4)) {
      Dosis_NPK = str1.toFloat();
      NPK_N = str2.toFloat();
      NPK_P = str3.toFloat();
      NPK_K = str4.toFloat();
      Serial.println("Data NPK diatur:");
      Serial.print("Dosis NPK: "); Serial.println(Dosis_NPK);
      Serial.print("NPK Nitrogen (N): "); Serial.println(NPK_N);
      Serial.print("NPK Phosphor (P): "); Serial.println(NPK_P);
      Serial.print("NPK Potassium (K): "); Serial.println(NPK_K);
      Serial.println("");

      // Perhitungan untuk NPK
      float NPK_N_Rasio = (NPK_N / 100) * Dosis_NPK;
      NPK_N_PPM = (NPK_N_Rasio / Volume_Air) * 1000000;
      float NPK_P_Rasio = (NPK_P / 100) * Dosis_NPK;
      NPK_P_PPM = (NPK_P_Rasio / Volume_Air) * 1000000;
      float NPK_K_Rasio = (NPK_K / 100) * Dosis_NPK;
      NPK_K_PPM = (NPK_K_Rasio / Volume_Air) * 1000000;

      // Cetak nilai NPK_Rasio
      Serial.print("Rasio NPK Nitrogen (N): "); Serial.println(NPK_N_Rasio);
      Serial.print("Rasio NPK Phosphor (P): "); Serial.println(NPK_P_Rasio);
      Serial.print("Rasio NPK Potassium (K): "); Serial.println(NPK_K_Rasio);

      // Cetak nilai NPK_PPM
      Serial.print("PPM NPK Nitrogen (N): "); Serial.println(NPK_N_PPM);
      Serial.print("PPM NPK Phosphor (P): "); Serial.println(NPK_P_PPM);
      Serial.print("PPM NPK Potassium (K): "); Serial.println(NPK_K_PPM);

    } else {
      Serial.println("Ops. Input untuk data NPK tidak valid.");
    }
  } else if (perintah == "kalium") {
    if (validFloat(str1) && validFloat(str2)) {
      Dosis_KNO3 = str1.toFloat();
      KNO3_N = str2.toFloat();
      KNO3_K = 0;  // Nilai Potassium tetap
      Serial.println("Data Kalium Nitrate diatur:");
      Serial.print("Dosis KNO3: "); Serial.println(Dosis_KNO3);
      Serial.print("Kalium Nitrat Nitrogen (N): "); Serial.println(KNO3_N);
      Serial.print("Kalium Nitrat Potassium (K): "); Serial.println(KNO3_K);
      Serial.println("");

      // Perhitungan untuk KNO3
      float KNO3_N_Rasio = (KNO3_N / 100) * Dosis_KNO3;
      KNO3_N_PPM = (KNO3_N_Rasio / Volume_Air) * 1000000;
      float KNO3_K_Rasio = (KNO3_K / 100) * Dosis_KNO3;
      KNO3_K_PPM = (KNO3_K_Rasio / Volume_Air) * 1000000;

      // Cetak nilai KNO3_Rasio
      Serial.print("Rasio KNO3 Nitrogen (N): "); Serial.println(KNO3_N_Rasio);
      Serial.print("Rasio KNO3 Potassium (K): "); Serial.println(KNO3_K_Rasio);

      // Cetak nilai KNO3_PPM
      Serial.print("PPM KNO3 Nitrogen (N): "); Serial.println(KNO3_N_PPM);
      Serial.print("PPM KNO3 Potassium (K): "); Serial.println(KNO3_K_PPM);

    } else {
      Serial.println("Ops. Input untuk data Kalium Nitrate tidak valid.");
    }
  } else if (perintah == "garam") {
    if (validFloat(str1) && validFloat(str2) && validFloat(str3)) {
      Dosis_MgSO4 = str1.toFloat();
      MgSO4_Mg = str2.toFloat();
      MgSO4_S = str3.toFloat();
      Serial.println("Data Garam Epsom diatur:");
      Serial.print("Dosis MgSO4: "); Serial.println(Dosis_MgSO4);
      Serial.print("Magnesium (Mg): "); Serial.println(MgSO4_Mg);
      Serial.print("Sulfur (S): "); Serial.println(MgSO4_S);
      Serial.println("");

      // Perhitungan untuk MgSO4
      float MgSO4_Mg_Rasio = (MgSO4_Mg / 100) * Dosis_MgSO4;
      MgSO4_Mg_PPM = (MgSO4_Mg_Rasio / Volume_Air) * 1000000;
      float MgSO4_S_Rasio = (MgSO4_S / 100) * Dosis_MgSO4;
      MgSO4_S_PPM = (MgSO4_S_Rasio / Volume_Air) * 1000000;

      // Cetak nilai MgSO4_Mg_Rasio dan MgSO4_S_Rasio
      Serial.print("Rasio Magnesium (Mg): "); Serial.println(MgSO4_Mg_Rasio);
      Serial.print("Rasio Sulfur (S): "); Serial.println(MgSO4_S_Rasio);

      // Cetak nilai MgSO4_Mg_PPM dan MgSO4_S_PPM
      Serial.print("PPM Magnesium (Mg): "); Serial.println(MgSO4_Mg_PPM);
      Serial.print("PPM Sulfur (S): "); Serial.println(MgSO4_S_PPM);

    } else {
      Serial.println("Ops. Input untuk data Garam Epsom tidak valid.");
    }
  } else if (perintah == "magsul") {
    if (validFloat(str1) && validFloat(str2) && validFloat(str3)) {
      Dosis_NH4H2PO4 = str1.toFloat();
      NH4H2PO4_N = str2.toFloat();
      NH4H2PO4_P = str3.toFloat();
      Serial.println("Data Fosfat Monoammonium diatur:");
      Serial.print("Dosis NH4H2PO4: "); Serial.println(Dosis_NH4H2PO4);
      Serial.print("Nitrogen (N): "); Serial.println(NH4H2PO4_N);
      Serial.print("Phosphor (P): "); Serial.println(NH4H2PO4_P);
      Serial.println("");

      // Perhitungan untuk NH4H2PO4
      float NH4H2PO4_N_Rasio = (NH4H2PO4_N / 100) * Dosis_NH4H2PO4;
      NH4H2PO4_N_PPM = (NH4H2PO4_N_Rasio / Volume_Air) * 1000000;
      float NH4H2PO4_P_Rasio = (NH4H2PO4_P / 100) * Dosis_NH4H2PO4;
      NH4H2PO4_P_PPM = (NH4H2PO4_P_Rasio / Volume_Air) * 1000000;

      // Cetak hasil perhitungan NH4H2PO4_N_Rasio dan NH4H2PO4_P_Rasio
      Serial.print("Rasio Nitrogen (N): "); Serial.println(NH4H2PO4_N_Rasio);
      Serial.print("Rasio Phosphor (P): "); Serial.println(NH4H2PO4_P_Rasio);

      // Cetak hasil perhitungan NH4H2PO4_N_PPM dan NH4H2PO4_P_PPM
      Serial.print("PPM Nitrogen (N): "); Serial.println(NH4H2PO4_N_PPM);
      Serial.print("PPM Phosphor (P): "); Serial.println(NH4H2PO4_P_PPM);

    } else {
      Serial.println("Ops. Input untuk data Fosfat Monoammonium tidak valid.");
    }
  } else if (perintah == "kalk") {
    if (validFloat(str1) && validFloat(str2) && validFloat(str3)) {
      Dosis_CaNO32 = str1.toFloat();
      CaNO32_N = str2.toFloat();
      CaNO32_Ca = str3.toFloat();
      Serial.println("Data Kalsium Nitrate diatur:");
      Serial.print("Dosis CaNO32: "); Serial.println(Dosis_CaNO32);
      Serial.print("Nitrogen (N): "); Serial.println(CaNO32_N);
      Serial.print("Kalsium (Ca): "); Serial.println(CaNO32_Ca);
      Serial.println("");

      // Perhitungan untuk CaNO32
      float CaNO32_N_Rasio = (CaNO32_N / 100) * Dosis_CaNO32;
      CaNO32_N_PPM = (CaNO32_N_Rasio / Volume_Air) * 1000000;
      float CaNO32_Ca_Rasio = (CaNO32_Ca / 100) * Dosis_CaNO32;
      CaNO32_Ca_PPM = (CaNO32_Ca_Rasio / Volume_Air) * 1000000;

      // Cetak hasil perhitungan CaNO32_N_Rasio dan CaNO32_Ca_Rasio
      Serial.print("Rasio Nitrogen (N): "); Serial.println(CaNO32_N_Rasio);
      Serial.print("Rasio Kalsium (Ca): "); Serial.println(CaNO32_Ca_Rasio);

      // Cetak hasil perhitungan CaNO32_N_PPM dan CaNO32_Ca_PPM
      Serial.print("PPM Nitrogen (N): "); Serial.println(CaNO32_N_PPM);
      Serial.print("PPM Kalsium (Ca): "); Serial.println(CaNO32_Ca_PPM);

    } else {
      Serial.println("Ops. Input untuk data Kalsium Nitrate tidak valid.");
    }
  } else if (perintah == "stok") {
    if (validFloat(str1) && validFloat(str2) && validFloat(str3) && validFloat(str4)) {
      // Menyimpan nilai dari input ke variabel terkait
      Pre_Solusi_Stok_A = str1.toFloat();  // Volume pekat A (mL)
      Final_Larutan_Solusi_Stok_A = str2.toFloat();  // Volume larutan akhir A (mL)
      Pre_Solusi_Stok_B = str3.toFloat();  // Volume pekat B (mL)
      Final_Larutan_Solusi_Stok_B = str4.toFloat();  // Volume larutan akhir B (mL)

      Serial.println("Data Solusi Stok diatur:");
      Serial.print("Solusi Stok A pekat: ");
      Serial.print(Pre_Solusi_Stok_A);
      Serial.print(" mL dan batasan dosis per ");
      Serial.println(Final_Larutan_Solusi_Stok_A);

      Serial.print("Solusi Stok B pekat: ");
      Serial.print(Pre_Solusi_Stok_B);
      Serial.print(" mL dan batasan dosis per ");
      Serial.println(Final_Larutan_Solusi_Stok_B);
      Serial.println("");

      // Perhitungan Konsentrasi Stok A
      Pre_Konsentrasi_Stok_A = (Dosis_NPK + Dosis_KNO3 + Dosis_MgSO4 + Dosis_NH4H2PO4) / Pre_Solusi_Stok_A;
      Final_Larutan_Konsentrasi_Stok_A = (Dosis_NPK + Dosis_KNO3 + Dosis_MgSO4 + Dosis_NH4H2PO4) / Volume_Air;
      Estimasi_Vol_A = (Final_Larutan_Konsentrasi_Stok_A * Final_Larutan_Solusi_Stok_A) / Pre_Konsentrasi_Stok_A;

      // Perhitungan Konsentrasi Stok B
      Pre_Konsentrasi_Stok_B = Dosis_CaNO32 / Pre_Solusi_Stok_B;
      Final_Larutan_Konsentrasi_Stok_B = Dosis_CaNO32 / Volume_Air;
      Estimasi_Vol_B = (Final_Larutan_Konsentrasi_Stok_B * Final_Larutan_Solusi_Stok_B) / Pre_Konsentrasi_Stok_B;

      // Menampilkan hasil perhitungan untuk Solusi Stok A
      Serial.print("Tambahkan semua bahan kimia (A) ke dalam ");
      Serial.print(Pre_Solusi_Stok_A);
      Serial.println(" mL air.");

      Serial.print("Ambil ");
      Serial.print(Estimasi_Vol_A);
      Serial.print(" mL solusi stok A untuk dilarutkan dalam ");
      Serial.print(Final_Larutan_Solusi_Stok_A / 1000);
      Serial.println(" L air.");
      Serial.println("");

      // Menampilkan hasil perhitungan untuk Solusi Stok B
      Serial.print("Tambahkan semua bahan kimia (B) ke dalam ");
      Serial.print(Pre_Solusi_Stok_B);
      Serial.println(" mL air.");

      Serial.print("Ambil ");
      Serial.print(Estimasi_Vol_B);
      Serial.print(" mL solusi stok B untuk dilarutkan dalam ");
      Serial.print(Final_Larutan_Solusi_Stok_B / 1000);
      Serial.println(" L air.");


    } else {
      Serial.println("Ops. Input untuk data Solusi Stok tidak valid.");
    }
  } else if (perintah == "hitung") {
    if (Volume_Air <= 0) {
      Serial.println("Error: Volume air universal tidak valid.");
      return;
    }

    // Validasi jika input yang diperlukan telah diatur
    if (Dosis_NPK > 0 && NPK_N > 0 &&
        NPK_P > 0 && NPK_K > 0 && Dosis_KNO3 > 0 &&
        KNO3_N > 0 && Dosis_MgSO4 > 0 && MgSO4_Mg > 0 &&
        MgSO4_S > 0 && Dosis_NH4H2PO4 > 0 && NH4H2PO4_N > 0 &&
        NH4H2PO4_P > 0 && Dosis_CaNO32 > 0 && CaNO32_N > 0 &&
        CaNO32_Ca > 0) {

      // Perhitungan PPM akhir
      float PPM_N_Akhir = NPK_N_PPM + KNO3_N_PPM + CaNO32_N_PPM + NH4H2PO4_N_PPM;
      float PPM_P_Akhir = NPK_P_PPM + NH4H2PO4_P_PPM;
      float PPM_K_Akhir = NPK_K_PPM + KNO3_K_PPM;
      float PPM_Mg_Akhir = MgSO4_Mg_PPM;
      float PPM_S_Akhir = MgSO4_S_PPM;
      float PPM_Ca_Akhir = CaNO32_Ca_PPM;

      // Cetak hasil perhitungan PPM akhir ke Serial Monitor
      Serial.println("Hasil Perhitungan PPM Akhir:");
      Serial.print("PPM Nitrogen (N): "); Serial.println(PPM_N_Akhir);
      Serial.print("PPM Phosphor (P): "); Serial.println(PPM_P_Akhir);
      Serial.print("PPM Kalium (K): "); Serial.println(PPM_K_Akhir);
      Serial.print("PPM Magnesium (Mg): "); Serial.println(PPM_Mg_Akhir);
      Serial.print("PPM Sulfur (S): "); Serial.println(PPM_S_Akhir);
      Serial.print("PPM Kalsium (Ca): "); Serial.println(PPM_Ca_Akhir);

    } else {
      Serial.println("Ops. Input untuk perhitungan tidak lengkap atau tidak valid.");
    }
  } else {
    Serial.println("Ops. Perintah Tidak Ditemukan.");
  }
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  dapatPerintah();
  if (semuaPerintah.length() > 0) {
    eksekusiPerintah();
  }
}
