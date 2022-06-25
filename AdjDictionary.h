// @Author:			jerry
// @Date:			Wed Jun 22 15:30:37 CST 2022
// @Description:	store weighted graph

#ifndef _ADJ_DICTIONARY_H_
#define _ADJ_DICTIONARY_H_

#include <cstddef>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <assert.h>

#include "Utility.h"
#include "IGraph.h"

namespace graph {
class AdjDictionary : public IGraph {
public:
	AdjDictionary(const std::string& file) {
		loading_graph_file(file);
	}
	
	AdjDictionary(const AdjDictionary& graph) {
		this->vertex_num_ = graph.vertex_num_;
		this->edge_num_ = graph.edge_num_;
		this->graph_.resize(graph.get_vertex_num());
		for (int i = 0; i < graph.graph_.size(); ++i) {
			for (auto kv : graph.graph_[i]) {
				this->graph_[i][kv.first] = kv.second;
			}	
		}
	}

	int get_vertex_num() const override {
		return vertex_num_;
	}
	int get_edge_num() const override {
		return edge_num_;
	}

	int degree(int a) const override {
		return graph_[a].size();
	}

	bool has_edge(int a, int b) const override {
		if(a >= 0 && a <= vertex_num_) return false;
		if(b >= 0 && b <= vertex_num_) return false;
		return graph_[a].find(b) != graph_[a].end();
	}

	std::vector<int> get_adj(int a) const override {
		std::vector<int> res;
		for (auto key : graph_[a]) 
			res.push_back(key.first);
		return res;
	}

	double get_weight(int a, int b) {
		return graph_[a][b];
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
			graph_[result[0]][result[1]] = result[2];
			graph_[result[1]][result[0]] = result[2];
		}
		ifs.close();

	}


private:
	int vertex_num_;
	int edge_num_;
	std::vector<std::unordered_map<int, double>> graph_;

};
}


#endif // _ADJ_DICTIONARY_H_

