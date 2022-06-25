#ifndef _ADJ_TABLE_H_
#define _ADJ_TABLE_H_

#include <cstddef>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <assert.h>

#include "Utility.h"
#include "IGraph.h"

namespace graph {
class AdjTable : public IGraph{
public:
	AdjTable(const std::string& file) {
		loading_graph_file(file);

	}
	AdjTable(const std::vector<std::vector<int>>& graph
			, int vertex_num, int edge_num) {
		vertex_num_ = vertex_num;
		edge_num_ = edge_num;
		graph_.reserve(vertex_num_);
		for (int i = 0; i < graph.size(); ++i) {
			for (int j = 0; j < graph[i].size(); ++j) {
				graph_[i].push_back(graph[i][j]);
				graph_[graph[i][j]].push_back(i);
			}
		}
	}
	AdjTable(const AdjTable& graph) {
		this->vertex_num_ = graph.vertex_num_;
		this->edge_num_ = graph.edge_num_;
		this->graph_.resize(graph.get_vertex_num());
		for (int i = 0; i < graph.graph_.size(); ++i) {
			for (int j = 0; j < graph.graph_[i].size(); ++j) {
				this->graph_[i].push_back(graph.graph_[i][j]);
			}
		}
	}
	~AdjTable() { };

	int get_vertex_num() const override {
		return vertex_num_;
	}
	int get_edge_num() const override {
		return edge_num_;
	}

	bool has_edge(int a, int b) const override { 
		if(a >= 0 && a <= vertex_num_) return false;
		if(b >= 0 && b <= vertex_num_) return false;
		return std::find(graph_[a].begin(), graph_[a].end(), b) != 
				graph_[a].end();
	}

	int degree(int a) const override {
		return graph_[a].size();
	}

	std::vector<int> get_adj(int a) const override {
		 return graph_[a];
	}
	

private:
	void loading_graph_file(const std::string& file) {
		std::ifstream ifs(file);
		if (!ifs.is_open()) {
			std::cout << "==== loading graph failed! ====" 
				      << std::endl;
			exit(0);
		}
		std::string line;
		std::getline(ifs, line);
		std::vector<int> result;
		split(line, ' ', result);
		vertex_num_ = result[0];
		edge_num_ = result[1];
		graph_.resize(vertex_num_);
		while (std::getline(ifs, line)) {
			result.clear();
			split(line, ' ', result);
			graph_[result[0]].push_back(result[1]);
			graph_[result[1]].push_back(result[0]);
		}
		ifs.close();

	}


private:
	int vertex_num_;
	int edge_num_;
	std::vector<std::vector<int>> graph_;

};
}


#endif // _ADJ_TABLE_H_

