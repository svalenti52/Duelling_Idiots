//
// Created by svale on 5/11/2022.
//

/**
* pert.cpp
 *
*/

#include <iostream>
#include <vector>
#include <random>

struct Tasks
{
    int task_id;
    std::vector<int> rng_work;
    int early_start;
    int early_finish;
    int late_start;
    int late_finish;
    std::vector<int> next_task;
    std::vector<int> prev_task;
    int work_performed;
    Tasks(int i_task_id, std::vector<int> i_rng_wrk, int i_early_start, int i_early_finish,
          int i_late_start, int i_late_finish, std::vector<int> i_next_task,
          std::vector<int> i_prev_task, int i_work_performed) : task_id(i_task_id),
          rng_work(std::move(i_rng_wrk)), early_start(i_early_start), early_finish(i_early_finish),
          late_start(i_late_start), late_finish(i_late_finish), next_task(std::move(i_next_task)),
                                                prev_task(std::move(i_prev_task)),
                                                work_performed(i_work_performed) {}
};

std::ostream& operator << (std::ostream& o, Tasks& tasks)
{
    o << "tn=" << tasks.task_id
        << " es=" << tasks.early_start
        << " ls=" << tasks.late_start
        << " ef=" << tasks.early_finish
        << " lf=" << tasks.late_finish
        << " wp=" << tasks.work_performed << '\n';
    return o;
}

int main()
{
    using namespace std;

    const int nr_tasks = 8;

    const int task1 = 0;
    const int task2 = 1;
    const int task3 = 2;
    const int task4 = 3;
    const int task5 = 4;
    const int task6 = 5;
    const int task7 = 6;
    const int task8 = 7;

    const int nr_events = 100;

    vector<int> work_array;
    vector<int> critical_task(nr_tasks, 0);

    // Task1
    vector<Tasks> tasks;
    std::vector<int> work_v{0};
    std::vector<int> next{task2, task3};
    std::vector<int> prev{};
    tasks.emplace_back(1, work_v, 0, 0, 100, 100, next, prev, 0);

    // Task2
    work_v = {2, 3, 4};
    next = {task4, task5};
    prev = {task1};
    tasks.emplace_back(2, work_v, 0, 0, 100, 100, next, prev, 0);

    // Task3
    work_v = {1, 2};
    next = {task4, task5};
    prev = {task1};
    tasks.emplace_back(3, work_v, 0, 0, 100, 100, next, prev, 0);

    // Task4
    work_v = {1, 2};
    next = {task6};
    prev = {task2, task3};
    tasks.emplace_back(4, work_v, 0, 0, 100, 100, next, prev, 0);

    // Task5
    work_v = {2, 3, 4};
    next = {task7};
    prev = {task2, task3};
    tasks.emplace_back(5, work_v, 0, 0, 100, 100, next, prev, 0);

    // Task6
    work_v = {2, 3, 4};
    next = {task7};
    prev = {task4};
    tasks.emplace_back(6, work_v, 0, 0, 100, 100, next, prev, 0);

    // Task7
    work_v = {1, 2};
    next = {task8};
    prev = {task5, task6};
    tasks.emplace_back(7, work_v, 0, 0, 100, 100, next, prev, 0);

    // Task8
    work_v = {0};
    next = {};
    prev = {task7};
    tasks.emplace_back(8, work_v, 0, 0, 100, 100, next, prev, 0);

    for (int ix = 0; ix < nr_events; ++ix)
    {
        for (Tasks& task : tasks)
        {
            int sz_rng = task.rng_work.size();

            std::random_device rd;
            default_random_engine dre(rd());
            uniform_int_distribution<int> uid(0, sz_rng-1);
            task.work_performed = task.rng_work[uid(dre)];
            task.early_finish = task.work_performed + task.early_start;
            for (int t : task.next_task)
                if (task.early_finish > tasks[t].early_start)
                    tasks[t].early_start = task.early_finish;
            if (task.next_task.empty()) {
                task.late_finish = task.early_finish;
            }
        }

        for (auto task_reverse = tasks.rbegin(); task_reverse != tasks.rend(); ++task_reverse)
        {
            task_reverse->late_start = task_reverse->late_finish - task_reverse->work_performed;
            for (int& t : task_reverse->prev_task) {
                if (task_reverse->late_start < tasks[t].late_finish) {
                    tasks[t].late_finish = task_reverse->late_start;
                }
            }
        }


        for (int jx = 0; jx < nr_tasks; ++jx)
            if (tasks[jx].early_start == tasks[jx].late_start)
                ++critical_task[jx];

        for (Tasks& task : tasks)
        {
            // cout << task;
            task.early_start = 0;
            task.late_start = 0;
            task.early_finish = 100;
            task.late_finish = 100;
        }
    }

    cout << "\ncritical path results\n";
    for (int cp : critical_task)
        cout << cp << ' ';
    cout << '\n';

}
