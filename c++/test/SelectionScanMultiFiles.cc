/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <chrono>
#include <future>
#include <iostream>
#include <list>
#include <memory>
#include <mutex>
#include <queue>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <vector>
#include <string_view>
#include <algorithm>
#include <sstream>

#include "Adaptor.hh"
#include "MemoryInputStream.hh"
#include "MemoryOutputStream.hh"
#include "orc/OrcFile.hh"
#include "orc/sargs/SearchArgument.hh"
#include "orc/ColumnPrinter.hh"
#include "Stats.hh"
#include "json.hpp"
// #include "stats.h"
// #include "wrap/orc-proto-wrapper.hh"

using namespace orc;

// std::list<std::string> cols = {"key5790", "key3806", "key4339", "key1858", "key8846", "key1239", "key6409", "key1661", "key5345", "key3646", "key3319", "key863", "key7557", "key1207", "key6747", "key4304", "key223", "key6671", "key2410", "key7677", "key6178", "key1151", "key5588", "key952", "key673", "key8793", "key205", "key8885", "key6530", "key2676", "key692", "key5885", "key9994", "key4584", "key1386", "key1912", "key5026", "key5659", "key2854", "key2540", "key5033", "key8240", "key3478", "key3190", "key4918", "key2029", "key8055", "key8761", "key4818", "key1615", "key9756", "key6935", "key2506", "key1423", "key7306", "key1047", "key7826", "key7560", "key8120", "key9562", "key4458", "key9541", "key9680", "key1897", "key6082", "key8370", "key7240", "key6527", "key7092", "key7776", "key9104", "key215", "key9866", "key357", "key694", "key763", "key8613", "key8179", "key718", "key3457", "key6873", "key5754", "key7522", "key9958", "key7447", "key608", "key5871", "key6667", "key3919", "key2673", "key2166", "key325", "key7411", "key2061", "key439", "key4374", "key5571", "key1090", "key7997", "key3120", "val5790", "val3806", "val4339", "val1858", "val8846", "val1239", "val6409", "val1661", "val5345", "val3646", "val3319", "val863", "val7557", "val1207", "val6747", "val4304", "val223", "val6671", "val2410", "val7677", "val6178", "val1151", "val5588", "val952", "val673", "val8793", "val205", "val8885", "val6530", "val2676", "val692", "val5885", "val9994", "val4584", "val1386", "val1912", "val5026", "val5659", "val2854", "val2540", "val5033", "val8240", "val3478", "val3190", "val4918", "val2029", "val8055", "val8761", "val4818", "val1615", "val9756", "val6935", "val2506", "val1423", "val7306", "val1047", "val7826", "val7560", "val8120", "val9562", "val4458", "val9541", "val9680", "val1897", "val6082", "val8370", "val7240", "val6527", "val7092", "val7776", "val9104", "val215", "val9866", "val357", "val694", "val763", "val8613", "val8179", "val718", "val3457", "val6873", "val5754", "val7522", "val9958", "val7447", "val608", "val5871", "val6667", "val3919", "val2673", "val2166", "val325", "val7411", "val2061", "val439", "val4374", "val5571", "val1090", "val7997", "val3120"};
std::list<std::string> cols = {"url", "caption"};
// std::vector<uint64_t> row_ids;

int single_file(const std::string& filename, const std::vector<int64_t>& rows) 
{

  ReaderOptions readerOpts;
  std::unique_ptr<Reader> reader =
      createReader(readLocalFile(filename), readerOpts);
  RowReaderOptions rowReaderOpts;
  rowReaderOpts.include(cols);
  std::unique_ptr<SearchArgument> sarg;
  auto sarg_builder = SearchArgumentFactory::newBuilder();
  *sarg_builder = sarg_builder
        ->startOr();
  std::string row_id_name = "row_id";

  for (const auto row : rows){
    sarg_builder->equals(row_id_name, PredicateDataType::LONG, Literal(static_cast<int64_t>(row)));
  }
  sarg = sarg_builder->end().build();
  rowReaderOpts.searchArgument(std::move(sarg));
  auto rowReader = reader->createRowReader(rowReaderOpts);
  auto readBatch = rowReader->createRowBatch(1024);
  
  // auto begin = std::chrono::steady_clock::now();
  uint64_t cnt = 0;
  while (rowReader->next(*readBatch))
  {
    cnt += readBatch->numElements;
  }

  // std::cout << "read orc(s): " << (static_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - begin)).count() <<std::endl;
  // std::cout << "read meta (us): " << time_meta << std::endl;
  // std::cout << "startNextStripe (us): " << time_startNextStripe << std::endl;
  // std::cout << "buildReader (us): " << time_buildReader << std::endl;
  // std::cout << "total read:" << cnt << std::endl;
  // system("cat /proc/$PPID/io");
  return 0;
}

class ThreadPool {
 public:
  explicit ThreadPool(size_t numThreads) {
    workers.reserve(numThreads);
    for (size_t i = 0; i < numThreads; ++i) {
      workers.emplace_back([this] {
        while (true) {
          std::function<void()> task;
          {
            std::unique_lock<std::mutex> lock(this->queueMutex);
            this->condition.wait(lock,
                                 [this] { return this->stop || !this->tasks.empty(); });
            if (this->stop && this->tasks.empty()) return;
            task = std::move(this->tasks.front());
            this->tasks.pop();
          }
          task();
        }
      });
    }
  }

  template <class F>
  void enqueue(F&& f) {
    {
      std::unique_lock<std::mutex> lock(queueMutex);
      tasks.emplace(std::forward<F>(f));
    }
    condition.notify_one();
  }

  ~ThreadPool() {
    {
      std::unique_lock<std::mutex> lock(queueMutex);
      stop = true;
    }
    condition.notify_all();
    for (std::thread& worker : workers) worker.join();
  }

 private:
  std::vector<std::thread> workers;
  std::queue<std::function<void()>> tasks;
  std::mutex queueMutex;
  std::condition_variable condition;
  bool stop = false;
};

int main(int argc, char** argv) {
  std::ifstream ifs = std::ifstream(argv[1]);
  nlohmann::json ex_jf = nlohmann::json::parse(ifs);
  std::map<std::string, std::vector<int64_t>> file_to_ids;
  for (auto& item : ex_jf.items()) {
    // convert comma separated ids into rows
    std::stringstream ss(std::string(item.value()));
    std::string id;
    while (std::getline(ss, id, ',')) {
      file_to_ids[item.key()].push_back(std::stoi(id));
    }
  }

  auto* pool = new ThreadPool(8);  // Use 8 threads
  // std::cout << "total num of files: " << file_to_ids.size() << std::endl;
  auto begin = std::chrono::steady_clock::now();
  for (const auto& item : file_to_ids) {
    pool->enqueue([item] {
      // std::ostringstream cmd;
      // cmd << "scan_exec_pq --columns=1,2 --rows=" << item.second << " " << item.first;
      // auto c_str = const_cast<char*>(cmd.str().c_str());
      single_file(item.first, item.second);
      // std::cout << "finished " << item.first << std::endl;
      // std::system(cmd.str().c_str());
    });
  }
  delete pool;
  auto total_time = (static_cast<std::chrono::duration<double>>(
                         std::chrono::steady_clock::now() - begin))
                        .count();
  std::cout << "total time: " << total_time << " seconds." << std::endl;
  // system("cat /proc/$PPID/io");
  return 0;
}