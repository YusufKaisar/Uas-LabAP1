#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string activity;
    string time;
    bool completed;
};

vector<Task> tasks; // Vector yang akan menyimpan daftar tugas

void addTask() { // Fungsi untuk menambahkan tugas
    Task newTask; // Membuat objek Task baru
    cout << "Task " << tasks.size() + 1 << ":" << endl;
    cout << "Aktivitas atau pekerjaan hari ini : ";
    cin.ignore();
    cin >> newTask.activity; // Memasukkan aktivitas tugas
    cout << "Waktu aktivitas (Jam, contoh = 08:30) : ";
    cin >> newTask.time; // Memasukkan waktu tugas
    newTask.completed = false; // Menandai bahwa tugas belum selesai

    tasks.push_back(newTask); // Menambahkan tugas baru ke vector tasks

    cout << "Task added successfully!" << endl;
    cout << endl;
}

void viewTask() { // fungsi untuk melihat task
    if (!tasks.empty()) { // mengecek vector tasks 
        cout << "Aktivitas hari ini :" << endl;
        for (size_t i = 0; i < tasks.size(); i++) { // perulangan untuk menjalankan dari vector tasks. 
            const Task& task = tasks[i];
            cout << "[" << i + 1 << "] " << task.activity << " (" << task.time << ") - "
                 << (task.completed ? "Completed" : "Pending") << endl; //output dari aktivitas yang sudah diisi
        }
    } else {
        cout << "Belum ada aktivitas" << endl;
    }
    cout << endl;
}

void updateTask() { // fungsi untuk mengupdaye task
    int index;

    while (true) {
        viewTask(); // memanggil fungsi viewTask()

        // Cek jika viewTask belum terisi atau masih kosong
        if (tasks.empty()) {
            cout << "Belum ada aktivitas! Kembali ke menu awal." << endl;
            cout << endl;
            return; // kembali ke menu awal
        }

        cout << "Masukkan nomor yang ingin diubah : ";
        cin >> index; // Memasukkan nomor tugas yang ingin diubah

        if (index >= 1 && index <= tasks.size()) { // Memeriksa apakah nomor tugas valid
            Task& task = tasks[index - 1]; // Mengakses tugas yang dipilih dalam vector tasks

            cout << "Data " << index << endl;
            cout << "1. Update Aktivitas" << endl;
            cout << "2. Update Waktu" << endl;
            cout << "3. Tandai sebagai selesai" << endl;
            cout << "Masukkan pilihan anda : ";

            int choice;
            cin >> choice; // Memasukkan pilihan untuk memperbarui tugas

            switch (choice) {
                case 1:
                    cout << "Masukkan aktivitas baru : ";
                    cin.ignore();
                    cin >> task.activity; // Memperbarui aktivitas tugas
                    cout << "Aktivitas berhasil diubah!" << endl;
                    cout << endl;
                    break;
                case 2:
                    cout << "Masukkan Waktu baru : ";
                    cin.ignore();
                    cin >> task.time; // Memperbarui waktu tugas
                    cout << "Aktivitas berhasil diubah!" << endl;
                    cout << endl;
                    break;
                case 3:
                    task.completed = true; // Menandai tugas sebagai selesai
                    cout << "Aktivitas ditandai sebagai selesai." << endl;
                    cout << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid. Update dibatalkan." << endl;
                    cout << endl;
                    break;
            }
            break;
        } else {
            cout << "Aktivitas tidak ada! Masukkan nomor yang benar." << endl;
            cout << endl;
        }
    }
}

void deleteTask() { // Fungsi untuk menghapus tugas
    int index;

    while (true) {
        viewTask(); // Memanggil fungsi viewTask() 
        cout << "Masukkan nomor Aktivitas yang ingin dihapus : ";
        cin >> index; // Memasukkan nomor tugas yang ingin dihapus

        if (index >= 1 && index <= tasks.size()) { // Memeriksa apakah nomor tugas ada
            tasks.erase(tasks.begin() + index - 1); // Menghapus task yang sudah ada dari vector tasks
            cout << "Aktivitas berhasil dihapus." << endl;
            cout << endl;
            break;
        } else {
            cout << "Aktivitas tidak ada! Masukkan nomor yang benar." << endl;
            cout << endl;
        }
    }
}

int main() {
    int choice;
    do {
        cout << "==== Todo List ====" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Update task" << endl;
        cout << "4. Remove task" << endl;
        cout << "5. Exit" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTask();
                cout << "Tekan enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                cout << endl;
                break;
            case 3:
                updateTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                cout << "Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                cout << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
