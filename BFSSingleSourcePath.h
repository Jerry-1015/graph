// @Author:			jerry
// @Date:			Tue Jun 21 17:35:51 CST 2022
// @Description:	BFS single source path

#ifndef _BFS_SINGLE_SOURCE_PATH_H_
#define _BFS_SINGLE_SOURCE_PATH_H_

#include "IGraph.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
#include <queue>

namespace graph {
class BFSSingleSourcePath {
public:
	BFSSingleSourcePath(IGraph* graph, int s) : graph_(graph), s_(s) 
							 , visited_(graph_->get_vertex_num(), false)
							 , pre_(graph_->get_vertex_num(), -1) 
							 , distance_(graph_->get_vertex_num(), -1)
	{
				BFS(s);
    }
	BFSSingleSourcePath(const BFSSingleSourcePath&) = delete;
	BFSSingleSourcePath(const BFSSingleSourcePath&&) = delete;
	BFSSingleSourcePath& operator=(const BFSSingleSourcePath&) = delete;
	BFSSingleSourcePath& operator=(const BFSSingleSourcePath&&) = delete;

	bool is_conn_to(int t) const {
		return visited_[t];
	}

	std::vector<int> get_path(int t) const  {
		std::vector<int> res;
		if (!is_conn_to(t)) return res;
		int cur = t;
		while (cur != s_) {
			res.push_back(cur);
			cur = pre_[cur];
		}
		res.push_back(s_);
		std::reverse(res.begin(), res.end());
		return res;
	}

	int get_distance(int t) const {
		return distance_[t];
	}

private:
	void BFS(int s) {
		visited_[s] = true;
		distance_[s] = 0;
		que_.push(s);
		while (!que_.empty()) {
			int v = que_.front();
			que_.pop();
			for (auto w : graph_->get_adj(v)) {
				if (!visited_[w]) {
					visited_[w] = true;
					pre_[w] = v;
					distance_[w] = distance_[v] + 1;
					que_.push(w);
				}
					
			}
		}
	}


private:
	IGraph* graph_;
	int s_;
	std::vector<bool> visited_;
	std::vector<int> pre_;
	std::queue<int> que_;
	std::vector<int> distance_;
};
}

#endif // _BFS_SINGLE_SOURCE_PATH_H_
