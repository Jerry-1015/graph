// @Author:			jerry
// @Date:			Tue Jun 21 10:31:34 CST 2022
// @Description:	search single source path

#ifndef _DFS_SINGLE_SOURCE_PATH_H_
#define _DFS_SINGLE_SOURCE_PATH_H_

#include "IGraph.h"
#include <algorithm>
#include <cstddef>
#include <vector>


namespace graph {
class DFSSingleSourcePath {
public:
	DFSSingleSourcePath(IGraph* graph, int s) : graph_(graph), s_(s) 
						     , pre_(graph_->get_vertex_num(), -1)
							 , visited_(graph_->get_vertex_num(), false)
	{
		DFS(s);
	}
	DFSSingleSourcePath(const DFSSingleSourcePath&) = delete;
	DFSSingleSourcePath(const DFSSingleSourcePath &&) = delete;
	DFSSingleSourcePath& operator=(const DFSSingleSourcePath&) = delete;
	DFSSingleSourcePath& operator=(const DFSSingleSourcePath &&) = delete;

	bool is_conn_to(int t) const {
		return visited_[t];
	}
	std::vector<int> get_path(int t) {
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

private:
	void DFS(int v) {
		visited_[v] = true;
		for (auto w : graph_->get_adj(v)) {
			if (!visited_[w]) {
				pre_[w] = v;
				DFS(w);
			}
		}
	}

private:
	IGraph* graph_;
	int s_;
	std::vector<int> pre_;
	std::vector<bool> visited_;
		
};
}


#endif // _DFS_SINGLE_SOURCE_PATH_H_
