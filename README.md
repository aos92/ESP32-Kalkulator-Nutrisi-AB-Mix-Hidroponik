# ESP32 Kalkulator Nutrisi AB Mix Hidroponik

Program ini membantu Anda menghitung konsentrasi nutrisi dalam larutan hidroponik berdasarkan input dosis yang diberikan untuk berbagai senyawa. 

## 1. Tentukan Volume Air
- **Volume_Air:** Masukkan volume air dalam gram (biasanya sama dengan ml). Misalnya, jika Anda menggunakan 25 liter air, maka `Volume_Air` adalah 25000.

  **Perintah:** `?volair=Nilai_Volume_Air`

## 2. Masukkan Data Nutrisi untuk NPK
- **Dosis_NPK:** Masukkan dosis pupuk NPK dalam gram.
- **NPK_N:** Masukkan persentase Nitrogen (N) dalam pupuk NPK.
- **NPK_P:** Masukkan persentase Fosfor (P) dalam pupuk NPK.
- **NPK_K:** Masukkan persentase Kalium (K) dalam pupuk NPK.

  **Perintah:** `?npk=Dosis_NPK;NPK_N;NPK_P;NPK_K`

  Program akan menghitung PPM (parts per million) dari N, P, dan K berdasarkan input ini.

## 3. Masukkan Data Nutrisi untuk Kalium Nitrat (KNO3)
- **Dosis_KNO3:** Masukkan dosis Kalium Nitrat dalam gram.
- **KNO3_N:** Masukkan persentase Nitrogen (N) dalam Kalium Nitrat.
- **KNO3_K:** Masukkan persentase Kalium (K) dalam Kalium Nitrat.

  **Perintah:** `?kalium=Dosis_KNO3;KNO3_N;KNO3_K`

  PPM untuk Nitrogen dan Kalium dari KNO3 akan dihitung.

## 4. Masukkan Data Nutrisi untuk Garam Epsom (MgSO4)
- **Dosis_MgSO4:** Masukkan dosis Garam Epsom dalam gram.
- **MgSO4_Mg:** Masukkan persentase Magnesium (Mg) dalam Garam Epsom.
- **MgSO4_S:** Masukkan persentase Sulfur (S) dalam Garam Epsom.

  **Perintah:** `?garam=Dosis_MgSO4;MgSO4_Mg;MgSO4_S`

  PPM untuk Magnesium dan Sulfur akan dihitung.

## 5. Masukkan Data Nutrisi untuk Monoammonium Fosfat (NH4H2PO4)
- **Dosis_NH4H2PO4:** Masukkan dosis Monoammonium Fosfat dalam gram.
- **NH4H2PO4_N:** Masukkan persentase Nitrogen (N) dalam Monoammonium Fosfat.
- **NH4H2PO4_P:** Masukkan persentase Fosfor (P) dalam Monoammonium Fosfat.

  **Perintah:** `?magsul=Dosis_NH4H2PO4;NH4H2PO4_N;NH4H2PO4_P`

  PPM untuk Nitrogen dan Fosfor akan dihitung.

## 6. Masukkan Data Nutrisi untuk Kalsium Nitrat (CaNO32)
- **Dosis_CaNO32:** Masukkan dosis Kalsium Nitrat dalam gram.
- **CaNO32_N:** Masukkan persentase Nitrogen (N) dalam Kalsium Nitrat.
- **CaNO32_Ca:** Masukkan persentase Kalsium (Ca) dalam Kalsium Nitrat.

  **Perintah:** `?kalk=Dosis_CaNO32;CaNO32_N;CaNO32_Ca`

  PPM untuk Nitrogen dan Kalsium akan dihitung.

## 7. Hitung PPM Akhir
- Program akan menjumlahkan PPM dari berbagai sumber untuk setiap elemen (N, P, K, Mg, S, Ca).
- Hasil PPM akhir untuk setiap elemen akan ditampilkan.

  **Perintah:** `?hitung`

## 8. Instruksi untuk Persiapan Solusi Stok A dan B
- **Volume_Solusi_Stok_A** dan **Volume_Solusi_Stok_B:** Tentukan volume untuk membuat solusi stok A dan B.
- Program akan memberikan instruksi mengenai berapa banyak bahan kimia yang harus ditambahkan ke air untuk membuat solusi stok A dan B.
- Anda juga akan mendapatkan instruksi tentang berapa banyak dari solusi stok ini yang harus diencerkan ke dalam volume air akhir.

  **Perintah:** `?stok=Volume_Solusi_Stok_A;Volume_Solusi_Dilarutkan_Akhir_A;Volume_Solusi_Stok_B;Volume_Solusi_Dilarutkan_Akhir_B`

  Tambahan:
  - **Pre_Solusi_Stok_A = 100** dan **Pre_Solusi_Stok_B = 100**
  - **Final_Larutan_Solusi_Stok_A = 1000** dan **Final_Larutan_Solusi_Stok_B = 1000**

  Angka 100 dan 1000 merupakan bagian dari masukan juga yang harus ditetapkan, ini digunakan untuk menghitung dan mengarahkan pembuatan solusi stok A dan B. Volume larutan stok kemudian dilarutkan lebih lanjut menjadi 1000 ml air untuk menghasilkan larutan akhir yang akan digunakan dalam sistem hidroponik Anda.


## Contoh Perhitungan Manual Komposisi Bahan

### Diketahui:
- **Volume_Air = 25000**  
- **Dosis_NPK = 10**
- **NPK_N = 24**
- **NPK_P = 8**
- **NPK_K = 16**
- **Dosis_KNO3 = 4.5**
- **KNO3_N = 13**
- **KNO3_K = 44**
- **Dosis_MgSO4 = 7**
- **MgSO4_Mg = 9.9**
- **MgSO4_S = 13**
- **Dosis_NH4H2PO4 = 1.5**
- **NH4H2PO4_N = 12.2**
- **NH4H2PO4_P = 26.99**
- **Dosis_CaNO32 = 10.3**
- **CaNO32_N = 17**
- **CaNO32_Ca = 24.5**
- **Pre_Solusi_Stok_A = 100**
- **Final_Larutan_Solusi_Stok_A = 1000**
- **Pre_Solusi_Stok_B = 100**
- **Final_Larutan_Solusi_Stok_B = 1000**

### Penyelesaian:
#### 1. **Perhitungan untuk NPK**
   - **NPK_N_Rasio** = (24 / 100) * 10 = 2.4 gram
   - **NPK_N_PPM** = (2.4 / 25000) * 1000000 = 96 PPM

   - **NPK_P_Rasio** = (8 / 100) * 10 = 0.8 gram
   - **NPK_P_PPM** = (0.8 / 25000) * 1000000 = 32 PPM

   - **NPK_K_Rasio** = (16 / 100) * 10 = 1.6 gram
   - **NPK_K_PPM** = (1.6 / 25000) * 1000000 = 64 PPM

#### 2. **Perhitungan untuk Kalium Nitrat (KNO3)**
   - **KNO3_N_Rasio** = (13 / 100) * 4.5 = 0.585 gram
   - **KNO3_N_PPM** = (0.585 / 25000) * 1000000 = 23.4 PPM

   - **KNO3_K_Rasio** = (44 / 100) * 4.5 = 1.98 gram
   - **KNO3_K_PPM** = (1.98 / 25000) * 1000000 = 79.2 PPM

#### 3. **Perhitungan untuk Garam Epsom (MgSO4)**
   - **MgSO4_Mg_Rasio** = (9.9 / 100) * 7 = 0.693 gram
   - **MgSO4_Mg_PPM** = (0.693 / 25000) * 1000000 = 27.72 PPM

   - **MgSO4_S_Rasio** = (13 / 100) * 7 = 0.91 gram
   - **MgSO4_S_PPM** = (0.91 / 25000) * 1000000 = 36.4 PPM

#### 4. **Perhitungan untuk Monoammonium Fosfat (NH4H2PO4)**
   - **NH4H2PO4_N_Rasio** = (12.2 / 100) * 1.5 = 0.183 gram
   - **NH4H2PO4_N_PPM** = (0.183 / 25000) * 1000000 = 7.32 PPM

   - **NH4H2PO4_P_Rasio** = (26.99 / 100) * 1.5 = 0.40485 gram
   - **NH4H2PO4_P_PPM** = (0.40485 / 25000) * 1000000 = 16.194 PPM

#### 5. **Perhitungan untuk Kalsium Nitrat (CaNO32)**
   - **CaNO32_N_Rasio** = (17 / 100) * 10.3 = 1.751 gram
   - **CaNO32_N_PPM** = (1.751 / 25000) * 1000000 = 70.04 PPM

   - **CaNO32_Ca_Rasio** = (24.5 / 100) * 10.3 = 2.5235 gram
   - **CaNO32_Ca_PPM** = (2.5235 / 25000) * 1000000 = 100.94 PPM

#### 6. **Perhitungan PPM Akhir untuk Setiap Elemen**
   - **Final_N_PPM** = 96 (NPK_N_PPM) + 23.4 (KNO3_N_PPM) + 7.32 (NH4H2PO4_N_PPM) + 70.04 (CaNO32_N_PPM) = **196.76 PPM**
   - **Final_P_PPM** = 32 (NPK_P_PPM) + 16.194 (NH4H2PO4_P_PPM) = **48.194 PPM**
   - **Final_K_PPM** = 64 (NPK_K_PPM) + 79.2 (KNO3_K_PPM) = **143.2 PPM**
   - **Final_Mg_PPM** = **27.72 PPM** (Hanya dari MgSO4_Mg_PPM)
   - **Final_S_PPM** = **36.4 PPM** (Hanya dari MgSO4_S_PPM)
   - **Final_Ca_PPM** = **100.94 PPM** (Hanya dari CaNO32_Ca_PPM)

#### **Hasil Akhir PPM**
- **Nitrogen (N):** 196.76 PPM
- **Fosfor (P):** 48.194 PPM
- **Kalium (K):** 143.2 PPM
- **Magnesium (Mg):** 27.72 PPM
- **Sulfur (S):** 36.4 PPM
- **Kalsium (Ca):** 100.94 PPM.

Hasil ini menunjukkan konsentrasi setiap elemen nutrisi dalam larutan hidroponik Anda setelah menghitung semua kontribusi dari berbagai senyawa. Anda dapat menggunakan data ini untuk menyiapkan solusi stok dan larutan akhir sesuai kebutuhan sistem hidroponik Anda.

### Contoh Perhitungan Manual untuk Solusi Stok

### Solusi Stok untuk A

1. **Konsentrasi Stok (C1):**
   - **Pre_Konsentrasi_Stok_A** = (Dosis_NPK + Dosis_KNO3 + Dosis_MgSO4 + Dosis_NH4H2PO4) / Pre_Solusi_Stok_A
   - **Pre_Konsentrasi_Stok_A** = (10 + 4.5 + 7 + 1.5) / 100
   - **Pre_Konsentrasi_Stok_A** = 23 / 100 = 0.23 gram/ml

2. **Volume yang Dihilangkan dan Dilarutkan (V1):**
   - **Estimasi_Vol_A** = (Final_Larutan_Konsentrasi_Stok_A * Final_Larutan_Solusi_Stok_A) / Pre_Konsentrasi_Stok_A
   - **Final_Larutan_Konsentrasi_Stok_A** = (Dosis_NPK + Dosis_KNO3 + Dosis_MgSO4 + Dosis_NH4H2PO4) / Volume_Air
   - **Final_Larutan_Konsentrasi_Stok_A** = 23 / 25000 = 0.00092 gram/ml
   - **Estimasi_Vol_A** = (0.00092 * 1000) / 0.23
   - **Estimasi_Vol_A** = 4 ml

3. **Konsentrasi Akhir (C2):**
   - **Final_Larutan_Konsentrasi_Stok_A** = (Dosis_NPK + Dosis_KNO3 + Dosis_MgSO4 + Dosis_NH4H2PO4) / Volume_Air
   - **Final_Larutan_Konsentrasi_Stok_A** = 23 / 25000 = 0.00092 gram/ml

4. **Pembuatan Dan Penggunaan Solusi Stok A:**
   - Campurkan  semua bahan ke dalam 100 mil air sebagai stok Anda.
   - Jika Anda memerlukan 1000 ml (1 liter) larutan akhir, gunakan 4 ml dari solusi stok A yang berisi 100 ml larutan pekat.

### Solusi Stok untuk B

1. **Konsentrasi Stok (C1):**
   - **Pre_Konsentrasi_Stok_B** = Dosis_CaNO32 / Pre_Solusi_Stok_B
   - **Pre_Konsentrasi_Stok_B** = 10.3 / 100
   - **Pre_Konsentrasi_Stok_B** = 0.103 gram/ml

2. **Volume yang Dihilangkan dan Dilarutkan (V1):**
   - **Estimasi_Vol_B** = (Final_Larutan_Konsentrasi_Stok_B * Final_Larutan_Solusi_Stok_B) / Pre_Konsentrasi_Stok_B
   - **Final_Larutan_Konsentrasi_Stok_B** = Dosis_CaNO32 / Volume_Air
   - **Final_Larutan_Konsentrasi_Stok_B** = 10.3 / 25000 = 0.000412 gram/ml
   - **Estimasi_Vol_B** = (0.000412 * 1000) / 0.103
   - **Estimasi_Vol_B** = 4 ml

3. **Konsentrasi Akhir (C2):**
   - **Final_Larutan_Konsentrasi_Stok_B** = Dosis_CaNO32 / Volume_Air
   - **Final_Larutan_Konsentrasi_Stok_B** = 10.3 / 25000 = 0.000412 gram/ml

4. **Pembuatan Dan Penggunaan Solusi Stok B:**
   - Campurkan  semua bahan ke dalam 100 mil air sebagai stok Anda.
   - Jika Anda memerlukan 1000 ml (1 liter) larutan akhir, gunakan 4 ml dari solusi stok B yang berisi 100 ml larutan pekat.


