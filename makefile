BIN     = bin
FMCSA   = find_max_crossing_subarray
IAS     = IA_solution
IST     = insertion_sort_t
LMSA    = liner_time_max_subarray
MERGE   = merge
MERGE_T = merge_t
VMS     = violate_max_subarray
STRA    = 4.2_strassen
COUNT_SORT = 8.2_counting_sort
MINIMUMMAXIMUM = 9.1_MinimumMaximum
RS = 9.2_RandomizedSelect
RQ = 7.3_RandomizedQuicksort
QS = 7.1_quicksort

CFLAGS = -g -Wall

all : ${BIN}/${COUNT_SORT} ${BIN}/${RS} ${BIN}/${QS} ${BIN}/${FMCSA} ${BIN}/${RQ} ${BIN}/${IAS} ${BIN}/${IST} ${BIN}/${LMSA} ${BIN}/${MERGE} ${BIN}/${MERGE_T} ${BIN}/${VMS} ${BIN}/${STRA} ${BIN}/${MINIMUMMAXIMUM}

${BIN}/${COUNT_SORT} : ${COUNT_SORT}/counting_sort.cpp
	g++ ${COUNT_SORT}/counting_sort.cpp ${CFLAGS} -o ${BIN}/${COUNT_SORT}

${BIN}/${FMCSA} : ${FMCSA}/main.cpp ${FMCSA}/max_sub_array.h
	g++ ${FMCSA}/main.cpp ${CFLAGS} -o ${BIN}/${FMCSA}

${BIN}/${IAS} : ${IAS}/insertion_sort.cpp ${IAS}/insertion_sort.h
	g++ ${IAS}/insertion_sort.cpp ${CFLAGS} -o ${BIN}/${IAS}

${BIN}/${IST} : ${IST}/${IST}.cpp ${IST}/${IST}.h
	g++ ${IST}/${IST}.cpp ${CFLAGS} -o ${BIN}/${IST}

${BIN}/${LMSA} : ${LMSA}/Source.cpp
	g++ ${LMSA}/Source.cpp ${CFLAGS} -o ${BIN}/${LMSA}

${BIN}/${MERGE} : ${MERGE}/${MERGE}.cpp  ${MERGE}/${MERGE}.h
	g++ -std=c++0x ${MERGE}/${MERGE}.cpp ${CFLAGS} -o ${BIN}/${MERGE}

${BIN}/${MERGE_T} : ${MERGE_T}/${MERGE_T}.cpp  ${MERGE_T}/${MERGE_T}.h
	g++ -std=c++0x ${MERGE_T}/${MERGE_T}.cpp ${CFLAGS} -o ${BIN}/${MERGE_T}

${BIN}/${VMS} : ${VMS}/Source.cpp
	g++ ${VMS}/Source.cpp ${CFLAGS} -o ${BIN}/${VMS}

${BIN}/${STRA} : ${STRA}/strassen.cpp ${STRA}/strassen.h
	g++ -std=c++0x ${STRA}/strassen.cpp ${CFLAGS} -o ${BIN}/${STRA}

${BIN}/${MINIMUMMAXIMUM} : ${MINIMUMMAXIMUM}/${MINIMUMMAXIMUM}.cpp
	g++ ${MINIMUMMAXIMUM}/${MINIMUMMAXIMUM}.cpp ${CFLAGS} -o ${BIN}/${MINIMUMMAXIMUM}
	
${BIN}/${RS} : ${RS}/${RS}.cpp
	g++ ${RS}/${RS}.cpp ${CFLAGS} -o ${BIN}/${RS}

${BIN}/${RQ} : ${RQ}/${RQ}.cpp
	g++ ${RQ}/${RQ}.cpp ${CFLAGS} -o ${BIN}/${RQ}
	
${BIN}/${QS} : ${QS}/${QS}.cpp ${QS}/${QS}.h
	g++ ${QS}/${QS}.cpp ${CFLAGS} -o ${BIN}/${QS}

clean:
	rm ${BIN}/*
