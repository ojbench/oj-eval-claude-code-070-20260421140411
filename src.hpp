#ifndef _SJTU_CPP_FINAL_SRC_HPP_
#define _SJTU_CPP_FINAL_SRC_HPP_

namespace sjtu {
    // FCFS method based CPU.
    inline pair<CPUState, uint> CPU_FCFS::run() {
        int idx = -1;
        for (int i = 0; i < (int)tasks.size(); ++i) {
            if (tasks[i].time > 0) { idx = i; break; }
        }
        if (idx == -1) {
            state = idle;
            return make_pair(idle, 0u);
        }
        --tasks[idx].time;
        state = busy;
        return make_pair(busy, tasks[idx].task_id);
    }

    // SRTF method based CPU.
    inline pair<CPUState, uint> CPU_SRTF::run() {
        int idx = -1;
        for (int i = 0; i < (int)tasks.size(); ++i) {
            if (tasks[i].time == 0) continue;
            if (idx == -1 || tasks[i].time < tasks[idx].time) {
                idx = i;
            }
        }
        if (idx == -1) {
            state = idle;
            return make_pair(idle, 0u);
        }
        --tasks[idx].time;
        state = busy;
        return make_pair(busy, tasks[idx].task_id);
    }

    // Priority method based CPU.
    inline pair<CPUState, uint> CPU_PRIORITY::run() {
        int idx = -1;
        for (int i = 0; i < (int)tasks.size(); ++i) {
            if (tasks[i].time == 0) continue;
            if (idx == -1 || tasks[i].priority < tasks[idx].priority) {
                idx = i;
            }
        }
        if (idx == -1) {
            state = idle;
            return make_pair(idle, 0u);
        }
        --tasks[idx].time;
        state = busy;
        return make_pair(busy, tasks[idx].task_id);
    }
}

#endif // _SJTU_CPP_FINAL_SRC_HPP_