# 🚂 Tren Tahmin Oyunu (C)

> Oyuncu ile bilgisayar arasında geçen, her doğru tahminin bir tren vagonu kazandırdığı, renkli terminal tabanlı sayı tahmin oyunu.
>
> *A turn-based number guessing game between the player and the computer, written in C with a colorful terminal UI.*

![Dil](https://img.shields.io/badge/Dil-C-00599C?logo=c&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?logo=windows&logoColor=white)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-5C2D91?logo=visualstudio&logoColor=white)

## 📌 Proje Hakkında

C dilinde terminal tabanlı oyun geliştirme pratiği amacıyla hazırlanmış bir projedir. Oyuncu ve bilgisayar sırayla sayı tutar ve birbirinin sayısını tahmin etmeye çalışır. Doğru tahmin edilen her sayı bir vagon kazandırır; vagonlar dolduğunda en çok vagona sahip olan taraf kazanır.

## 🎮 Oyun Kuralları

- Oyun bir oyuncu ile bilgisayar arasında oynanır.
- Her turda bir taraf sayı tutar, diğeri tahmin eder.
- Sayılar **1 ile 5** arasındadır ve her turda **1 tahmin hakkı** vardır.
- Doğru tahmin edilen her sayı bir vagon kazandırır; toplam **5 vagon** vardır.
- Daha önce yapılmış bir tahmin tekrar kabul edilmez.
- Tüm vagonlar dolduğunda oyun biter, en çok vagona sahip olan kazanır.

## ✨ Özellikler

- Oyuncu adıyla kişiselleştirilmiş oyun akışı
- Tahmin geçmişi kontrolü (aynı sayı iki kez tahmin edilemez)
- ANSI renk kodlarıyla zenginleştirilmiş terminal arayüzü
- Oyun sonunda kazananı kutlayan tren animasyonu

## 🛠️ Kullanılan Teknolojiler

| Alan | Teknoloji |
| --- | --- |
| Dil | C |
| Geliştirme ortamı | Visual Studio 2022 (MSVC) |
| Arayüz | ANSI escape kodlarıyla renklendirilmiş konsol |

## 📁 Proje Yapısı

```
.
├── TrenOyunu.sln               # Visual Studio çözüm dosyası
└── TrenOyunu/
    ├── TrenOyunu.c             # Oyunun kaynak kodu
    ├── TrenOyunu.vcxproj
    └── TrenOyunu.vcxproj.filters
```

| Fonksiyon | Görevi |
| --- | --- |
| `oyun()` | Ana oyun döngüsü |
| `oyuncuAdlariniAl()` | Oyuncu adının alınması |
| `oyuncuDegistir()` | Sıranın oyuncu ile bilgisayar arasında değişmesi |
| `tahminKontrol()` | Tekrarlanan tahminlerin engellenmesi |
| `trenGuncelle()` | Kazanılan vagonların trene eklenmesi |
| `tahminsifirlama()` | Tur sonunda tahmin geçmişinin sıfırlanması |

## 🚀 Çalıştırma

1. Depoyu klonlayın.
2. `TrenOyunu.sln` dosyasını Visual Studio 2022 ile açın.
3. **Ctrl + F5** ile derleyip çalıştırın.

## 👩‍💻 Geliştirici

**Zeynep Erdem** — [github.com/zeyerdm](https://github.com/zeyerdm)
