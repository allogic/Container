#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#ifdef TEST_VERBOSE
	#define TEST_BEGIN() printf("%s:\n", __func__)
#else
	#define TEST_BEGIN()
#endif // TEST_VERBOSE

#ifdef TEST_VERBOSE
	#define TEST_LOG(FMT, ...) printf(FMT, __VA_ARGS__)
#else
	#define TEST_LOG(FMT, ...)
#endif // TEST_VERBOSE

#define TEST_INT_LEQ(EXPR, EXPECTED) \
	{ \
		int64_t v = (EXPR); \
		int64_t e = (EXPECTED); \
		g_tests_total++; \
		if (v <= e) \
		{ \
			g_tests_passed++; \
		} \
		else \
		{ \
			g_tests_failed++; \
		} \
		TEST_LOG("\t[%s] " #EXPR " (%zd <= %zd)\n", ((v <= e) ? "PASSED" : "ERROR"), v, e); \
	}

#define TEST_INT_EQ(EXPR, EXPECTED) \
	{ \
		int64_t v = (EXPR); \
		int64_t e = (EXPECTED); \
		g_tests_total++; \
		if (v == e) \
		{ \
			g_tests_passed++; \
		} \
		else \
		{ \
			g_tests_failed++; \
		} \
		TEST_LOG("\t[%s] " #EXPR " (%zd == %zd)\n", ((v == e) ? "PASSED" : "ERROR"), v, e); \
	}

#define TEST_INT_GEQ(EXPR, EXPECTED) \
	{ \
		int64_t v = (EXPR); \
		int64_t e = (EXPECTED); \
		g_tests_total++; \
		if (v >= e) \
		{ \
			g_tests_passed++; \
		} \
		else \
		{ \
			g_tests_failed++; \
		} \
		TEST_LOG("\t[%s] " #EXPR " (%zd >= %zd)\n", ((v >= e) ? "PASSED" : "ERROR"), v, e); \
	}

#define TEST_FLT_LEQ(EXPR, EXPECTED) \
	{ \
		double_t v = (EXPR); \
		double_t e = (EXPECTED); \
		g_tests_total++; \
		if (v <= e) \
		{ \
			g_tests_passed++; \
		} \
		else \
		{ \
			g_tests_failed++; \
		} \
		TEST_LOG("\t[%s] " #EXPR " (%f <= %f)\n", ((v <= e) ? "PASSED" : "ERROR"), v, e); \
	}

#define TEST_FLT_EQ(EXPR, EXPECTED) \
	{ \
		double_t v = (EXPR); \
		double_t e = (EXPECTED); \
		g_tests_total++; \
		if (v == e) \
		{ \
			g_tests_passed++; \
		} \
		else \
		{ \
			g_tests_failed++; \
		} \
		TEST_LOG("\t[%s] " #EXPR " (%f == %f)\n", ((v == e) ? "PASSED" : "ERROR"), v, e); \
	}

#define TEST_FLT_GEQ(EXPR, EXPECTED) \
	{ \
		double_t v = (EXPR); \
		double_t e = (EXPECTED); \
		g_tests_total++; \
		if (v >= e) \
		{ \
			g_tests_passed++; \
		} \
		else \
		{ \
			g_tests_failed++; \
		} \
		TEST_LOG("\t[%s] " #EXPR " (%f >= %f)\n", ((v >= e) ? "PASSED" : "ERROR"), v, e); \
	}

#define TEST_STR_EQ(EXPR, EXPECTED) \
	{ \
		char const* v = (EXPR); \
		char const* e = (EXPECTED); \
		g_tests_total++; \
		if (strcmp(v, e) == 0) \
		{ \
			g_tests_passed++; \
		} \
		else \
		{ \
			g_tests_failed++; \
		} \
		TEST_LOG("\t[%s] " #EXPR " (\"%s\" == \"%s\")\n", ((strcmp(v, e) == 0) ? "PASSED" : "ERROR"), (strlen(v) ? v : ""), (strlen(e) ? e : "")); \
	}

#ifdef TEST_VERBOSE
	#define TEST_END()
#else
	#define TEST_END()
#endif // TEST_VERBOSE

extern void test_prologue(void);
extern void test_epilogue(void);

#ifdef TEST_IMPLEMENTATION
	uint64_t g_tests_total;
	uint64_t g_tests_passed;
	uint64_t g_tests_failed;
#else
	extern uint64_t g_tests_total;
	extern uint64_t g_tests_passed;
	extern uint64_t g_tests_failed;
#endif // TEST_IMPLEMENTATION

#ifdef TEST_IMPLEMENTATION
	void test_prologue(void)
	{
		g_tests_total = 0;
		g_tests_passed = 0;
		g_tests_failed = 0;
	}
	void test_epilogue(void)
	{
		printf("test_stats:\n");
		printf("\ttotal: %zu\n", g_tests_total);
		printf("\tpassed: %zu\n", g_tests_passed);
		printf("\tfailed: %zu\n", g_tests_failed);
	}
#endif // TEST_IMPLEMENTATION

#endif // TEST_H
