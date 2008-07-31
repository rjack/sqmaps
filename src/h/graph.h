/*
 * Copyright (c) 2008 Giacomo Ritucci
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GIACOMO RITUCCI ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 * NO EVENT SHALL GIACOMO RITUCCI BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef RJACK_GRAPH_H
#define RJACK_GRAPH_H

#include <sys/types.h>


#ifndef     vertex_id_t
#define     vertex_id_t        int
#endif

#ifndef     arch_weight_t
#define     arch_weight_t      int
#endif

#ifndef     vertex_value_t
#define     vertex_value_t     int
#endif


struct vertex;

typedef struct vertex adjacency_list_t;


/* Vertex */
typedef struct vertex {
	/* Unique identifier */
	vertex_id_t v_id;

	/* Vertex payload */
	vertex_value_t v_value;

	/* Directly reachable vertexes */
	adjacency_list_t *v_adjacent_vertexes;
} vertex_t;




/* Used in adjacency_list_t lists */
typedef struct adjacent {
	vertex_id_t a_id;
	arch_weight_t a_weight;
	struct adjacent *a_next;
} adjacent_vertex_t;


/* Graph */
typedef struct {
	vertex_t **g_vertex;
	size_t g_vertex_quantity;
} graph_t;


/* Iterator */
typedef struct {
	graph_t *gi_graph;

	/* Current vertex id, i.e. the id of the vertex returned by the last
	 * graph_iterator_get_next call. */
	vertex_id_t gi_current;
} graph_iterator_t;


typedef struct {
	graph_t *bc_graph;

	vertex_id_t bc_source;

	/* TODO callback:
	 * - vertex_is_target */

	/* TODO data structures:
	 * - visited
	 * - to_be_explored queue */
} bfs_context_t;


typedef struct {
	arch_weight_t *p_weight;

	adjacency_list_t *p_vertexes;
} path_t;

#endif /* RJACK_GRAPH_H */
