// @Author:			jerry
// @Date:			Mon Jun 20 20:31:24 CST 2022
// @Description:	DFS

#ifndef _DFS_GRAPH_H_
#define _DFS_GRAPH_H_

#include "AdjTable.h"
#include "IGraph.h"
#include <cstddef>
#include <vector>


namespace graph {
class DFSGraph {
public:
	DFSGraph(IGraph* graph) : graph_(graph) 
							 , visited_(graph->get_vertex_num(), false)
	{
		for (int v = 0; v < graph->get_vertex_num(); ++v)	{
			if (!visited_[v])
				DFS(v);
		}
	}
	DFSGraph(const DFSGraph&) = delete;
	DFSGraph(const DFSGraph &&) = delete;
	DFSGraph& operator=(const DFSGraph&) = delete;
	DFSGraph& operator=(const DFSGraph &&) = delete;

	std::vector<int> get_list() const {
		return list_;
	}
private:
	void DFS(int v) {
		visited_[v] = true;
		list_.push_back(v);
		for (auto w : graph_->get_adj(v)) {
			if (!visited_[w])
				DFS(w);
		}
	}

private:
	IGraph* graph_;
	std::vector<bool> visited_;
	std::vector<int> list_;
		

};
}


#endif // _DFS_GRAPH_H_
