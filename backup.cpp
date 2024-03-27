#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

// Function to log messages to a file
void logMessage(const std::string& message) {
    std::ofstream logFile;
    logFile.open("backup.log", std::ios_base::app);
    if (logFile.is_open()) {
        std::time_t result = std::time(nullptr);
        logFile << std::asctime(std::localtime(&result)) << " " << message << "\n";
        logFile.close();
    } else {
        std::cerr << "Error opening log file." << std::endl;
    }
}

int main() {
    // Source and destination folders
    std::string sourceFolder = "/home/ubuntuotabek/Test/manba";
    std::string destinationFolder = "/home/ubuntuotabek/Test/server";

    // Execute the rsync command
    std::string rsyncCommand = "rsync -avz " + sourceFolder + " " + destinationFolder;
    int result = std::system(rsyncCommand.c_str());

    // Log the result
    if (result == 0) {
        logMessage("Backup successful");
    } else {
        logMessage("Backup failed");
    }

    return 0;
}
