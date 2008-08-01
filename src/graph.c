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


#include "h/graph.h"
#include "h/util.h"
#include "h/types.h"

#include <assert.h>
#include <stdlib.h>


/****************************************************************************
			       Public functions
****************************************************************************/

graph_t *
graph_create (size_t graph_size)
{
	int i;
	graph_t *new_graph;

	assert (graph_size != 0);

	new_graph = malloc (sizeof(graph_t));
	check_allocation (new_graph);

	new_graph->g_vertex_quantity = 0;
	new_graph->g_size = graph_size;
	new_graph->g_vertex = malloc (graph_size * sizeof(vertex_t *));
	check_allocation (new_graph->g_vertex);

	for (i = 0; i < graph_size; i++)
		new_graph->g_vertex[i] = NULL;

	return new_graph;
}


int
graph_add_vertex
(graph_t *graph, vertex_t *new_vertex, graph_add_vertex_option_t auto_id)
{
	assert (graph != NULL);
	assert (new_vertex != NULL);

	/* Set new_vertex id */
	switch (auto_id) {

	case ID_MANUALLY_SET:
		if (!graph_is_valid_vertex_id (graph, new_vertex->v_id)
		    || graph_contains_vertex_id (new_vertex->v_id))
			return 0;
		break;

	case ID_AUTO_INCREMENT:
		if (graph_is_full (graph))
			return 0;
		new_vertex->v_id = graph->g_vertex_quantity;
		break;

	default:
		return 0;
	}

	graph->g_vertex[new_vertex->v_id] = new_vertex;
	graph->g_vertex_quantity++;

	return 1;
}


int
graph_arch_create
(vertex_t *from_vertex, vertex_t *to_vertex, arch_weight_t weight)
{
	/* TODO */
	return 0;
}


vertex_t *
vertex_create (vertex_id_t *id, vertex_value_t value)
{
	/* TODO */
	return NULL;
}


graph_iterator_t *
graph_get_iterator (graph_t *graph)
{
	/* TODO */
	return NULL;
}


bool_t
graph_is_full (graph_t *graph)
{
	assert (graph != NULL);
	assert (graph->g_vertex_quantity < graph->g_size);

	if (graph->g_vertex_quantity = graph->g_size - 1)
		return TRUE;
	return FALSE;
}


bool_t
graph_is_valid_vertex_id (graph_t *graph, vertex_id_t id)
{
	assert (graph != NULL);

	if (id < 0 || id >= graph->g_size)
		return TRUE;
	return FALSE;
}

vertex_t *
graph_iterator_get_next (graph_iterator_t *iterator)
{
	/* TODO */
	return NULL;
}


vertex_t *
graph_get_vertex (vertex_id_t *id)
{
	/* TODO */
	return NULL;
}


bfs_context_t *
bfs_context_create (graph_t *graph, vertex_id_t *source_id)
{
	/* TODO */
	return NULL;
}


void
bfs_context_destroy (bfs_context_t *bfs_context)
{
	/* TODO */
}


path_t *
bfs_run (bfs_context_t *bfs_context)
{
	/* TODO */
	return NULL;
}
