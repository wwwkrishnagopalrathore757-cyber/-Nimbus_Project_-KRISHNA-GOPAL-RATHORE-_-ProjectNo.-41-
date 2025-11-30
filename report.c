#include <stdio.h>
#include "report.h"
#include "config.h"

void print_trip_report(const RouteResult *result, const Bin *bins, int bin_count) {
    printf("\n===== Smart Waste Collection Trip Report =====\n");
    printf("Total bins serviced (>= %.1f%% full): %d\n", FILL_THRESHOLD, result->bins_serviced);
    printf("Total distance travelled: %.2f units\n", result->total_distance);
    printf("Approx total time: %.1f minutes\n", result->total_time_min);
    printf("---------------------------------------------\n");
    printf("Serviced Bins Details:\n");

    for (int i = 0; i < bin_count; i++) {
        if (bins[i].serviced) {
            printf("Bin ID: %d | Location: (%.2f, %.2f) | Fill: %.1f%% | Priority: %d\n",
                   bins[i].id,
                   bins[i].x,
                   bins[i].y,
                   bins[i].fill_level,
                   bins[i].priority);
        }
    }

    printf("=============================================\n");
    printf("// Note: Ye ek simple simulator hai, real life me aur bhi constraints hote hain\n");
}
