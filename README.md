# Dosya Yönetim Sistemi 📁

Bu proje, basit bir dosya yönetim sistemi uygulamasını içerir. Kullanıcılara dosya oluşturma, silme, listeleme ve dosya içeriğini görüntüleme gibi temel dosya işlemlerini gerçekleştirme imkanı sağlar. 

## Özellikler ✨

- **Dosya Oluşturma 📂:** Kullanıcılara dosya oluşturma seçeneği sunar. Dosya oluşturulurken dosya adı ve oluşturulacak dizin belirtilir. 
  - Örnek: `create_file("dosya.txt", "/home/kullanici/")`

- **Dosya Silme 🗑️:** Kullanıcılara mevcut dosyaları silme seçeneği sunar. Silinecek dosyanın adı belirtilir ve sistemden kaldırılır.
  - Örnek: `delete_file("dosya.txt")`

- **Dosya Listeleme 📋:** Belirli bir klasördeki tüm dosyaların listesini görüntülemeyi sağlar. Kullanıcı, klasör yolunu belirterek içerisindeki dosyaları görebilir.
  - Örnek: `list_files("/home/kullanici/")`

- **Dosya İçeriğini Görüntüleme 👁️:** Kullanıcıya, belirtilen dosyanın içeriğini görüntüleme seçeneği sunar. Dosya adı verilir ve içerik terminalde gösterilir.
  - Örnek: `view_file("dosya.txt")`

## Gereksinimler ⚙️

- **GNU Make 🖥️:** Proje dosyalarını derlemek için kullanılan araçtır. Projeyi derlemek için terminalde `make` komutunu kullanın.
- **GCC Derleyici 🛠️:** Projenin C kodunu derlemek için GCC kullanılır. Projenin başarılı bir şekilde derlenmesi için gerekli olan C derleyicisidir.

## Kullanım 🚀

1. **Terminal Açın:** Proje klasöründe terminali açın.
2. **Derleme Yapın:** Proje dosyalarını derlemek için terminalde `make` komutunu kullanın. Bu, gerekli tüm dosyaları derleyerek çalıştırılabilir bir binary dosyası oluşturur.
   - Komut: `make`
3. **Uygulamayı Çalıştırın:** Derlenen dosyayı çalıştırmak için binary dosyasını çalıştırın (`./file_management_app`). Bu komut, dosya yönetim sistemini başlatır ve kullanıma hazır hale getirir.
   - Komut: `./file_management_app`

## Katkılar 🤝

Bu proje her türlü katkıya açıktır. Eğer bir hata bulursanız veya bir öneriniz varsa, aşağıdaki adımları takip ederek katkıda bulunabilirsiniz:

1. **Fork Yapın:** Projeyi kendi GitHub hesabınıza fork yapın ve bir kopyasını oluşturun.
2. **Değişiklikler Yapın:** Kendi kopyanızda gerekli değişiklikleri yapın ve yeni özellikler ekleyin.
3. **Pull Request Gönderin:** Değişikliklerinizi ana projeye katkı olarak göndermek için bir pull request oluşturun. Yapılan değişiklikleri ve eklenen özellikleri açıklayan bir mesaj ekleyin.
4. **Geri Bildirim:** Geri bildirimlerde bulunmak için GitHub üzerinden bir issue açabilirsiniz.

Herhangi bir katkı, hata raporu veya öneri için projenin GitHub sayfasına başvurabilirsiniz.
