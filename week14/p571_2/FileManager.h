// FileManager.h
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "MonsterWorld.h"

class FileManager {
public:
    void saveRanking(const std::vector<RankingEntry>& ranking);
    void loadRanking();
private:
    const char* filename = "ranking.dat";
    std::vector<RankingEntry> ranking;
};

#endif
