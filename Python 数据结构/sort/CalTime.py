import time
from functools import wraps

def calculate_function_run_time_ms(func):
    @wraps(func)
    def call_fun(*args, **kwargs):
        start_time = time.time()
        f = func(*args, **kwargs)
        end_time = time.time()
        print('%s() run time：%.3f ms' % (func.__name__, 1000 * (end_time - start_time)))
        return f

    return call_fun


@calculate_function_run_time_ms
def sleepMs(ms):
    time.sleep(ms/1000)


if __name__ == "__main__":

    sleepMs(1000)
