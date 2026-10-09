# 🎮 TicTacToe — C++ & SFML 3

TicTacToe là dự án game cờ caro 3×3 được phát triển bằng **C++ và SFML 3**, hướng đến việc xây dựng một trò chơi hoàn chỉnh với giao diện đồ họa trực quan, hệ thống tài khoản người chơi, nhiều chế độ chơi và hệ thống quản lý điểm số.

Dự án được phát triển theo hướng mô-đun, tách biệt phần xử lý logic game và giao diện người dùng, tạo nền tảng thuận lợi cho việc mở rộng và phát triển các tính năng trong tương lai.

## ✨ Tính năng hiện tại

### 🎲 Gameplay
- Xây dựng bàn cờ TicTacToe kích thước 3×3.
- Xử lý nước đi và luân phiên lượt chơi.
- Hiển thị quân cờ X và O trên bàn cờ.
- Kiểm tra trạng thái thắng, thua và hòa.
- Xây dựng logic cho chế độ chơi với máy (PvE).

### 🖥️ Giao diện đồ họa
- Màn hình đăng nhập (Login).
- Màn hình đăng ký (Register).
- Menu chính (Main Menu).
- Màn hình chơi game (Game Screen).
- Hiển thị kết quả sau mỗi trận đấu.
- Xử lý sự kiện chuột và bàn phím.
- Tối ưu bố cục giao diện khi thay đổi kích thước cửa sổ.

### 👤 Hệ thống tài khoản
- Xây dựng giao diện đăng nhập và đăng ký.
- Thiết kế các trường nhập tên tài khoản và mật khẩu.
- Xử lý sự kiện nhập liệu và thao tác trên giao diện.

*Lưu ý: Các chức năng xác thực tài khoản, lưu trữ dữ liệu và quản lý phiên đăng nhập vẫn đang trong quá trình hoàn thiện.*

## 🚀 Roadmap — Kế hoạch phát triển

### 1. 🎮 Đa dạng chế độ chơi

- **PvP — Player vs Player:** Hai người chơi lần lượt thực hiện nước đi trên cùng một bàn cờ.
- **PvE Easy:** Máy sử dụng chiến thuật cơ bản, phù hợp với người mới.
- **PvE Hard:** Máy sử dụng chiến thuật nâng cao, ưu tiên nước đi chiến thắng và ngăn chặn đối thủ.
- Hoàn thiện chức năng chơi lại (Play Again).
- Bổ sung chức năng quay về menu chính (Back to Menu).

### 2. 🏆 Hệ thống điểm số và bảng xếp hạng

Dự kiến tích hợp cơ sở dữ liệu SQL để lưu trữ điểm số, lịch sử trận đấu và thành tích của người chơi.

**Quy tắc tính điểm dự kiến**

| Chế độ | Thắng | Thua | Hòa |
|---|---:|---:|---:|
| PvE Easy | +1 | -1 | 0 |
| PvE Hard | +3 | -3 | 0 |

Các chức năng dự kiến:
- Thiết kế cấu trúc cơ sở dữ liệu.
- Lưu điểm số sau mỗi trận đấu.
- Liên kết kết quả trận đấu với tài khoản người chơi.
- Hiển thị tổng điểm và lịch sử thi đấu.
- Xây dựng bảng xếp hạng người chơi.

### 3. 🔐 Hoàn thiện hệ thống tài khoản

- Kiểm tra tính hợp lệ của thông tin đăng nhập.
- Xác thực thông tin khi đăng ký tài khoản.
- Kiểm tra tài khoản trùng lặp và dữ liệu đầu vào.
- Tích hợp cơ sở dữ liệu để lưu trữ thông tin tài khoản.
- Quản lý trạng thái đăng nhập và thông tin người chơi.
- Bảo vệ mật khẩu bằng phương pháp băm phù hợp thay vì lưu mật khẩu dạng văn bản thuần.

## 🛠️ Công nghệ sử dụng

| Thành phần | Công nghệ |
|---|---|
| Ngôn ngữ lập trình | C++ |
| Thư viện đồ họa | SFML 3 |
| Môi trường phát triển | Visual Studio Code |
| Trình biên dịch | GCC (g++) |
| Bộ công cụ biên dịch | MinGW-w64 |
| Cơ sở dữ liệu dự kiến | SQLite hoặc MySQL |

*Cơ sở dữ liệu chưa được xác nhận là đã tích hợp hoàn chỉnh.*

## 📁 Cấu trúc dự án dự kiến

```text
TicTacToe/
├── assets/
│   ├── font.ttf
│   ├── X.png
│   └── O.png
├── src/
│   ├── main.cpp
│   ├── App.h
│   ├── App.cpp
│   ├── Game.h
│   ├── Game.cpp
│   ├── GameUI.h
│   ├── GameUI.cpp
│   ├── LoginUI.h
│   ├── LoginUI.cpp
│   ├── MenuUI.h
│   └── MenuUI.cpp
├── README.md
└── ...
```

*Cấu trúc trên mang tính minh họa; cần điều chỉnh theo cấu trúc thư mục thực tế của dự án.*

## 🎯 Mục tiêu dự án

- Củng cố kiến thức lập trình hướng đối tượng trong C++.
- Làm quen với việc xây dựng giao diện đồ họa bằng SFML 3.
- Rèn luyện kỹ năng tổ chức mã nguồn theo mô-đun.
- Tìm hiểu cách xử lý sự kiện, trạng thái game và thuật toán cho máy chơi.
- Từng bước tích hợp cơ sở dữ liệu và xây dựng hệ thống quản lý người chơi.

## 📌 Trạng thái dự án

**Đang phát triển (In Development).**

Các tính năng được bổ sung và hoàn thiện theo từng giai đoạn. Những chức năng trong roadmap là mục tiêu phát triển tiếp theo, không đồng nghĩa với việc đã được triển khai đầy đủ.

## 📄 License

Chưa xác định. Có thể bổ sung giấy phép mã nguồn mở phù hợp khi dự án sẵn sàng công bố.
