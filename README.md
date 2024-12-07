# File Management System 📁

This project contains a simple file management system application. It allows users to perform basic file operations such as creating, deleting, listing, and viewing file contents.

## Features ✨

- **Create File 📂:** Allows users to create a file by specifying the file name and the directory where the file should be created.
  - Example: `create_file("dosya.txt", "/home/kullanici/")`

- **Delete File 🗑️:** Provides the option to delete an existing file. The user specifies the file name, and it is removed from the system.
  - Example: `delete_file("dosya.txt")`

- **List Files 📋:** Allows users to view all files in a specified folder. By providing the folder path, users can see the files within it.
  - Example: `list_files("/home/kullanici/")`

- **View File Content 👁️:** Provides the option to view the contents of a specified file. The file name is given, and its contents are displayed in the terminal.
  - Example: `view_file("dosya.txt")`

## Requirements ⚙️

- **GNU Make 🖥️:** This tool is used to compile the project files. Use the make command in the terminal to compile the project.
- **GCC Compiler 🛠️:** GCC is used to compile the C code for the project. It is the required C compiler to successfully compile the projec

## Usage 🚀

1. **Open Terminal:** Open the terminal in the project folder.
2. **Compile the Project:** Use the make command in the terminal to compile the project files. This will compile the necessary files and create an executable binary file.
   - Command: `make`
3. **Uygulamayı Çalıştırın:** Run the Application: To run the compiled project, execute the binary file (`./file_management_app`). This command will start the file management system and make it ready to use.
   - Command: `./file_management_app`

## Contributions 🤝

This project is open to contributions. If you find a bug or have a suggestion, you can follow these steps to contribute:

1. **Fork the Repository:** Fork the project to your own GitHub account to create a copy.
2. **Make Changes:** Make the necessary changes or add new features to your copy.
3. **Submit a Pull Request:** To contribute your changes to the main project, create a pull request. Include a message explaining the changes and new features.
4. **Feedback:** You can open an issue on GitHub for feedback or to report bugs.

For any contributions, bug reports, or suggestions, please refer to the project's GitHub page.
