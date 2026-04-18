/**
 * @file search_engine.hpp
 * @brief Declaration of the SearchEngine class.
 *
 * This module defines a simplified search engine that stores web resources,
 * processes search queries, and provides ranked search results.
 */

#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <string>
#include <vector>

#include "searchQuery.hpp"
#include "webResource.hpp"

class SearchEngine
{
private:
    static int total_queries;

    std::vector<WebResource> web_resources;
    SearchQuery current_query;
    std::vector<WebResource> current_search_results;

    /**
     * @brief Checks whether a resource matches a query.
     *
     * @param[in] query     Search query to check
     * @param[in] resource  Resource that is checked
     * @return true if the query text occurs in the resource content,
     *         otherwise false
     */
    bool queryInResource(
        const SearchQuery &query,
        const WebResource &resource) const;

    /**
     * @brief Rebuilds the current result list based on the current query.
     *
     * Matching resources are collected, sorted, and limited according to
     * the maximum number of results.
     */
    void updateCurrentSearchResults();

public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty search engine without indexed resources.
     */
    SearchEngine();

    /**
     * @brief Prints basic information about the search engine.
     */
    void printInfo() const;

    /**
     * @brief Returns the total number of executed queries.
     *
     * @return Total number of queries
     */
    static int getTotalQueries();

    /**
     * @brief Increments the total number of executed queries.
     */
    static void incTotalQueries();

    /**
     * @brief Adds a new web resource to the search engine.
     *
     * @param[in] resource  Resource to be added
     */
    void addResource(const WebResource &resource);

    /**
     * @brief Removes a web resource by its URL.
     *
     * @param[in] url  URL of the resource to remove
     */
    void removeResource(const std::string &url);

    /**
     * @brief Returns the current search query.
     *
     * @return Current search query
     */
    SearchQuery getCurrentQuery() const;

    /**
     * @brief Sets the current search query.
     *
     * If the query is valid, the search results are updated.
     *
     * @param[in] query  New current query
     */
    void setCurrentQuery(const SearchQuery &query);

    /**
     * @brief Returns the current search results.
     *
     * @return Vector containing the current search results
     */
    std::vector<WebResource> getSearchResults() const;

    /**
     * @brief Sorts the current search results by ranking in descending order.
     */
    void sortCurrentResources();

    /**
     * @brief Prints the current relevant search results.
     */
    void printRelevantResults() const;
};

#endif