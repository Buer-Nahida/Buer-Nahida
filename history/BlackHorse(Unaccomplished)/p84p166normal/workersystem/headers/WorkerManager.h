#pragma once
#include "Worker/AllWorker.h"
#include "headers.h"
#define FILENAME ".workerSystemData.txt"

class WorkerManager {
public:
    WorkerManager();

    void ShowMenu();
    void ExitSystem();
    void AddSomeWorker();
    void ShowWorker();
    void DeleteWorker();
    void ChangeWorker();
    void FindWorker();
    void SortWorker();
    void ClearFile();

    long long m_WorkerNum;
    Worker **m_WorkerArray;
    bool m_FileIsEmpty;

    ifstream m_fin;
    ofstream m_fout;

    ~WorkerManager();

protected:
    long long GetWorkerNum();
    void InitWorkerArray();

    void PauseClear();
    void SaveFile();
    long long IsExist(long long ID);
    void IsExistName(string name);
    void SelectSort(bool AscendingSort);
    void AddWorker(long long arrayIndex, Worker **workerGroupName,
                   long long count);

    void DeleteWorkerArray();
};
