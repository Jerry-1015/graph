// @Author:			jerry
// @Date:			Tue Jun 21 10:14:22 CST 2022
// @Description:	count the number of component

#ifndef _DFSCC_H_
#define _DFSCC_H_

#include "IGraph.h"
#include <cstddef>
#include <vector>


namespace graph {
class DFSCC {
public:
	DFSCC(IGraph* graph) : graph_(graph), ccount_(0) 
							 , visited_(graph->get_vertex_num(), false)
	{
		for (int v = 0; v < graph_->get_vertex_num(); ++v)	{
			if (!visited_[v]) {
				DFS(v);
				++ccount_;
			}
		}
	}
	DFSCC(const DFSCC&) = delete;
	DFSCC(const DFSCC &&) = delete;
	DFSCC& operator=(const DFSCC&) = delete;
	DFSCC& operator=(const DFSCC &&) = delete;

	int get_components() {
		return ccount_;
	}

private:
	void DFS(int v) {
		visited_[v] = true;
		for (auto w : graph_->get_adj(v)) {
			if (!visited_[w])
				DFS(w);
		}
	}

private:
	IGraph* graph_;
	int ccount_;
	std::vector<bool> visited_;
};
}


#endif // _DFSCC_H_
