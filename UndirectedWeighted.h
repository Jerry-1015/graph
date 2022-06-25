// @Author:			jerry
// @Date:			Sat Jun 25 14:42:06 CST 2022
// @Description:	Undirected Weighted Graph

#ifndef _UNDIRECTED_WEIGHTED_GRAPH_H_
#define _UNDIRECTED_WEIGHTED_GRAPH_H_

#include "IGraph.h"
#include "AdjDictionary.h"
#include "AdjDictionary.h"
#include "DFSGraph.h"
#include "DFSCC.h"
#include "DFSCycleDetection.h"
#include "DFSBipartitionDetection.h"
#include "DFSSingleSourcePath.h"
#include "BFSGraph.h"
#include "BFSCC.h"
#include "BFSCycleDetection.h"
#include "BFSBipartitionDetection.h"
#include "BFSSingleSourcePath.h"
#include "RandomGraph.h"
#include "Kruskal.h"
#include "Prim.h"
#include "Dijkstra.h"

#include <iostream>
#include <vector>

namespace graph {
class UndirectedWeightedGraph {
public:
	UndirectedWeightedGraph(const std::string& file) {
		graph_ = new AdjDictionary(file);
	}

	~UndirectedWeightedGraph() { delete graph_; }

	int vertex_num() const {
		return graph_->get_vertex_num();
	}

	int edge_num() const {
		return graph_->get_edge_num();
	}

	bool has_edge(int p, int q) const  {
		return graph_->has_edge(p, q);
	}

	bool is_conn(int p, int q) const {
		return BFSSingleSourcePath(graph_, p).is_conn_to(q);
	}
	
	bool has_cycle() const  {
		return 	BFSCycleDetection(graph_).has_cycle();
	}

	bool is_bipartite() const {
		return BFSBipartitionDetection(graph_).is_bipartition();
	}

	int component() const {
		return BFSCC(graph_).get_components();
	}

	std::vector<int> dfs_graph() const {
		return DFSGraph(graph_).get_list();
	}

	std::vector<int> bfs_graph() const {
		return BFSGraph(graph_).get_list();
	}

	std::vector<int> random_graph() const {
		return RandomGraph(graph_).get_list();
	}

	std::vector<Edge> kruskal() const {
		return Kruskal(graph_).get_list();
	}

	std::vector<Edge> prim() const {
		return Prim(graph_).get_list();
	}

	int min_dist(int p, int q) const {
		return Dijkstra(graph_, p).dist_to(q);
	}


private:
	IGraph *graph_;
};
}

#endif // _UNDIRECTED_WEIGHTED_GRAPH_H_
