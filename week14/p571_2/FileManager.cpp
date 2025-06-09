// FileManager.cpp
#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

void FileManager::saveRanking(const std::vector<RankingEntry>& ranking) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) throw std::runtime_error("파일을 열 수 없습니다.");

    size_t size = ranking.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& entry : ranking) {
        size_t nameLen = entry.name.size();
        ofs.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        ofs.write(entry.name.c_str(), nameLen);
        ofs.write(reinterpret_cast<const char*>(&entry.score), sizeof(entry.score));
    }
}

void FileManager::loadRanking() {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) throw std::runtime_error("랭킹 파일이 없습니다.");

    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
    ranking.clear();

    for (size_t i = 0; i < size; i++) {
        size_t nameLen;
        ifs.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        std::string name(nameLen, '\0');
        ifs.read(&name[0], nameLen);
        int score;
        ifs.read(reinterpret_cast<char*>(&score), sizeof(score));
        ranking.push_back({name, score});
    }
}
