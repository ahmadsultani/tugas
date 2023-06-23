import os


def get_current_directory():
    return os.getcwd()


def change_directory(target_directory):
    try:
        os.chdir(target_directory)
        if get_current_directory != target_directory:
            raise Exception
        print("Direktori aktif berubah menjadi", target_directory)
    except Exception as e:
        print("Gagal mengubah direktori aktif")
        print("Error: ", e)


def is_path_exist(path):
    return os.path.exists(path)


def is_dir(path):
    return os.path.isdir(path)


def is_file(path):
    return os.path.isfile(path)


def create_new_directory(new_directory):
    try:
        os.mkdir(new_directory)
        if is_path_exist(new_directory):
            print("Direktori", new_directory, "telah dibuat.")
        else:
            print("Direktori", new_directory, "gagal dibuat.")
    except Exception as e:
        print("Gagal membuat direktori", new_directory)
        print("Direktori", new_directory, "sudah ada.")
        print("Error: ", e)


def get_directories():
    return os.listdir()


def get_directory_content():
    print("Isi direktori saat ini:")
    for item in get_directories():
        print(item)


def delete_directory(target_directory):
    try:
        os.rmdir(target_directory)
        if is_path_exist(target_directory):
            raise Exception
        print("Direktori", target_directory, "telah dihapus.")
    except Exception as e:
        print("Direktori", target_directory, "gagal dihapus.")
        print("Error: ", e)


def get_file_size(target_file):
    return os.path.getsize(target_file)


def join_path(path1, path2):
    # menggabungkan path menjadi satu
    return os.path.join(path1, path2)


def create_new_file(new_file):
    try:
        file = open(new_file, 'w')

        if is_path_exist(new_file):
            file.write("Contoh isi file.")
            print("File", new_file, "telah dibuat.")
        else:
            print("File", new_file, "gagal dibuat.")
        file.close()
    except Exception as e:
        print("Gagal membuat file", new_file)
        print("Error: ", e)


def overwrite_file(target_file, content):
    try:
        file = open(target_file, 'w')
        file.write(content)
        file.close()
    except Exception as e:
        print("Gagal menulis ke file", target_file)
        print("Error: ", e)


def append_to_file(target_file, content):
    try:
        file = open(target_file, 'a')
        file.write(content)
        file.close()
    except Exception as e:
        print("Error: ", e)


def get_file_content(target_file):
    try:
        file = open(target_file, 'r')
        if is_path_exist(target_file):
            print("Isi file:")
            print(file.read())
        file.close()
    except Exception as e:
        print("Error: ", e)


def delete_file(target_file):
    try:
        os.remove(target_file)
        if is_path_exist(target_file):
            print("File", target_file, "gagal dihapus.")
        else:
            print("File", target_file, "telah dihapus.")
    except Exception as e:
        print("Gagal menghapus file", target_file)
        print("Error: ", e)


def rename_file(target_file, new_name):
    try:
        os.rename(target_file, new_name)
        if is_path_exist(new_name):
            print("File", target_file, "telah diganti namanya menjadi", new_name)
        else:
            print("File", target_file, "gagal diganti namanya.")
    except Exception as e:
        print("Gagal mengganti nama file", target_file)
        print("Error: ", e)


def clear_screen():
    # nt = windows, else = linux/unix
    os.system('cls' if os.name == 'nt' else 'clear')


def system_command(command):
    os.system(command)


def menu():
    clear_screen()
    print("Selamat datang.")
    print("Silakan pilih menu yang tersedia:")
    print("1. Lihat direktori saat ini")
    print("2. Ubah direktori aktif")
    print("3. Lihat isi direktori saat ini")
    print("4. Hapus direktori")
    print("5. Buat direktori")
    print("6. Lihat isi file")
    print("7. Hapus file")
    print("8. Buat file")
    print("9. Ganti nama file")
    print("10. Tambahkan konten ke file")
    print("11. Timpa konten ke file")
    print("12. Tampilkan ukuran file")
    print("13. Jalankan perintah di command prompt")
    print("14. Keluar")
    input_user = input("Masukkan pilihan menu: ")
    return input_user


# main function
if __name__ == "__main__":
    while True:
        chosen = menu()

        if chosen == "1":
            clear_screen()
            print("=== Melihat Direkori Saat Ini ===\n")
            print(get_current_directory())

        elif chosen == "2":
            clear_screen()
            print("=== Mengubah Direktori Aktif ===\n")
            print("Nama direktori harus lengkap")
            print("Contoh:", get_current_directory())
            target_directory = input("Masukkan nama direktori: ")
            change_directory(target_directory)

        elif chosen == "3":
            clear_screen()
            print("=== Melihat Isi Direktori Saat Ini ===\n")
            get_directory_content()

        elif chosen == "4":
            clear_screen()
            print("=== Menghapus Direktori ===\n")
            target_directory = input("Masukkan nama direktori: ")
            delete_directory(target_directory)

        elif chosen == "5":
            clear_screen()
            print("=== Membuat Direktori ===\n")
            new_directory = input("Masukkan nama direktori: ")
            create_new_directory(new_directory)

        elif chosen == "6":
            clear_screen()
            print("=== Melihat Isi File ===\n")
            target_file = input("Masukkan nama file: ")
            get_file_content(target_file)

        elif chosen == "7":
            clear_screen()
            print("=== Menghapus File ===\n")
            target_file = input("Masukkan nama file: ")
            delete_file(target_file)

        elif chosen == "8":
            clear_screen()
            print("=== Membuat File ===\n")
            new_file = input("Masukkan nama file: ")
            create_new_file(new_file)

        elif chosen == "9":
            clear_screen()
            print("=== Mengganti Nama File ===\n")
            target_file = input("Masukkan nama file: ")
            new_name = input("Masukkan nama baru: ")
            rename_file(target_file, new_name)

        elif chosen == "10":
            clear_screen()
            print("=== Menambahkan Konten ke File ===")
            target_file = input("Masukkan nama file: ")
            konten = input("Tulis Konten:\n")
            append_to_file(target_file, konten)

        elif chosen == "11":
            clear_screen()
            print("=== Menimpa Konten ke File ===")
            target_file = input("Masukkan nama file: ")
            konten = input("Tulis Konten:\n")
            overwrite_file(target_file, konten)

        elif chosen == "12":
            clear_screen()
            print("=== Menampilkan Ukuran File ===\n")
            target_file = input("Masukkan nama file: ")
            print(get_file_size(target_file), "bytes")

        elif chosen == "13":
            clear_screen()
            print("=== Menjalankan Perintah di Command Prompt ===\n")
            command = input("Masukkan perintah: ")
            system_command(command)

        elif chosen == "14":
            clear_screen()
            print("=== Keluar ===\n")
            print("Terima kasih telah menggunakan program ini.")
            break

        else:
            clear_screen()
            print("Menu tidak tersedia.")

        input("Tekan enter untuk melanjutkan...")
