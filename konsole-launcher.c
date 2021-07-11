#include <systemd/sd-bus.h>
#include <systemd/sd-journal.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    sd_bus *bus = NULL;
    int ret = sd_bus_open_user(&bus);
    if (ret < 0) {
        printf("Failed to connect to system bus: %s", strerror(-ret));
        sd_journal_print(LOG_ERR, "Failed to connect to system bus: %s", strerror(-ret));
        return -ret;
    }

    sd_bus_error error = SD_BUS_ERROR_NULL;
    sd_bus_message *dbusRet = NULL;
    ret = sd_bus_call_method(bus,
                    "org.kde.konsole",            /* service to contact */
                    "/org/kde/konsole", /* object path */
                    "org.freedesktop.Application",  /* interface name */
                    "Activate",          /* method name */
                    &error,                                  /* object to return error in */
                    &dbusRet,                                /* return message on success */
                    "a{sv}",                            /* input signature */
                    // arguments
                    0             /* number of elements in a(rray), actually a map, describing unix-user */
                    );

    if (ret < 0) {
        printf("Failed to issue method call: %s (%s, %s)\n", error.message, strerror(errno), strerror(-ret));
        sd_journal_print(LOG_ERR, "Failed to issue method call: %s (%s, %s)\n", error.message, strerror(errno), strerror(-ret));
    }

    sd_bus_error_free(&error);
    sd_bus_message_unref(dbusRet);
    sd_bus_unref(bus);

    return -ret; /* systemd flips the sign */
}

