/*
 * Author: jeff Daniel
 * Project Version: 1.0
 * Description: SAU Map Assist
 * This code is licensed under the MIT License.
 */

#include "file.c"

/**
 * @brief Open a file in read mode
 *
 * @param file_path The path of the file to open
 * @return FILE** A pointer to the opened file
 */
FILE **rOpenFile(const char *file_path);

/**
 * @brief Open a file in write mode
 *
 * @param file_path The path of the file to open
 * @return FILE** A pointer to the opened file
 */
FILE **wOpenFile(const char *file_path);

/**
 * @brief Close a file
 *
 * @param file A pointer to the file to close
 * @return true If the file was closed successfully
 * @return false If an error occurred while closing the file
 */
bool closeFile(FILE **file);

/**
 * @brief Write a SAU map to a file
 *
 * @param file A pointer to the file to write to
 * @return true If the SAU map was written successfully
 * @return false If an error occurred while writing the SAU map
 */
bool wSAUMap(FILE *file);
