# Build info:

Remote server is an Ubuntu 20.04 VM (clean install)

This is being built via Visual Studio 2019 the following is the output of the build:

```Shell
Starting copying files to remote machine.
Copying 'C:\Users\User\Documents\repos\boost_log_troubleshooting\.gitignore' to '/home/ubuntu/.vs/boost_log_troubleshooting/ba191def-c91c-4ff0-91bf-cadc813132a3/src/.gitignore'.
[rsync] rsync -t --delete --delete-excluded -v -r --exclude=.vs --exclude=.git --exclude=out -8  "." rsync://ubuntu@localhost:60192/-home-ubuntu-.vs-boost_log_troubleshooting-ba191def-c91c-4ff0-91bf-cadc813132a3-src
[rsync] sending incremental file list
[rsync] deleting bin/
[rsync] ./
[rsync] .gitignore
[rsync] 
[rsync] sent 447 bytes  received 54 bytes  143.14 bytes/sec
[rsync] total size is 24,406  speedup is 48.71
Finished copying files (elapsed time 00h:00m:10s:907ms).
cd $HOME/.vs/boost_log_troubleshooting/ba191def-c91c-4ff0-91bf-cadc813132a3/out/build/Linux-GCC-Debug;/usr/bin/cmake --build "$HOME/.vs/boost_log_troubleshooting/ba191def-c91c-4ff0-91bf-cadc813132a3/out/build/Linux-GCC-Debug" --target boost_log_trouble ;

[1/2] Building CXX object CMakeFiles/boost_log_trouble.dir/main.cpp.o
[2/2] Linking CXX executable /home/ubuntu/.vs/boost_log_troubleshooting/ba191def-c91c-4ff0-91bf-cadc813132a3/src/bin/boost_log_trouble
FAILED: /home/ubuntu/.vs/boost_log_troubleshooting/ba191def-c91c-4ff0-91bf-cadc813132a3/src/bin/boost_log_trouble 
: && /usr/bin/c++  -g   CMakeFiles/boost_log_trouble.dir/main.cpp.o  -o /home/ubuntu/.vs/boost_log_troubleshooting/ba191def-c91c-4ff0-91bf-cadc813132a3/src/bin/boost_log_trouble   && :
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `main':
/home/ubuntu/.vs/boost_log_troubleshooting/ba191def-c91c-4ff0-91bf-cadc813132a3/src/main.cpp:17: undefined reference to `init_logging()'
/usr/bin/ld: /home/ubuntu/.vs/boost_log_troubleshooting/ba191def-c91c-4ff0-91bf-cadc813132a3/src/main.cpp:18: undefined reference to `boost::log::v2s_mt_posix::trivial::logger::get()'
/usr/bin/ld: /home/ubuntu/.vs/boost_log_troubleshooting/ba191def-c91c-4ff0-91bf-cadc813132a3/src/main.cpp:18: undefined reference to `boost::log::v2s_mt_posix::trivial::logger::get()'
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `boost::log::v2s_mt_posix::aux::light_rw_mutex::lock_shared()':
/home/ubuntu/.vcpkg_cpptruths/installed/x64-linux/include/boost/log/detail/light_rw_mutex.hpp:111: undefined reference to `pthread_rwlock_rdlock'
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `boost::log::v2s_mt_posix::aux::light_rw_mutex::unlock_shared()':
/home/ubuntu/.vcpkg_cpptruths/installed/x64-linux/include/boost/log/detail/light_rw_mutex.hpp:115: undefined reference to `pthread_rwlock_unlock'
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `boost::log::v2s_mt_posix::record::reset()':
/home/ubuntu/.vcpkg_cpptruths/installed/x64-linux/include/boost/log/core/record.hpp:157: undefined reference to `boost::log::v2s_mt_posix::record_view::public_data::destroy(boost::log::v2s_mt_posix::record_view::public_data const*)'
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `boost::log::v2s_mt_posix::record boost::log::v2s_mt_posix::sources::basic_composite_logger<char, boost::log::v2s_mt_posix::sources::severity_logger_mt<boost::log::v2s_mt_posix::trivial::severity_level>, boost::log::v2s_mt_posix::sources::multi_thread_model<boost::log::v2s_mt_posix::aux::light_rw_mutex>, boost::log::v2s_mt_posix::sources::features<boost::log::v2s_mt_posix::sources::severity<boost::log::v2s_mt_posix::trivial::severity_level> > >::open_record<boost::parameter::aux::tagged_argument_list_of_1<boost::parameter::aux::tagged_argument<boost::log::v2s_mt_posix::keywords::tag::severity, boost::log::v2s_mt_posix::trivial::severity_level const> > >(boost::parameter::aux::tagged_argument_list_of_1<boost::parameter::aux::tagged_argument<boost::log::v2s_mt_posix::keywords::tag::severity, boost::log::v2s_mt_posix::trivial::severity_level const> > const&)':
/home/ubuntu/.vcpkg_cpptruths/installed/x64-linux/include/boost/log/sources/basic_logger.hpp:460: undefined reference to `boost::log::v2s_mt_posix::core::get_logging_enabled() const'
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `boost::log::v2s_mt_posix::aux::record_pump<boost::log::v2s_mt_posix::sources::severity_logger_mt<boost::log::v2s_mt_posix::trivial::severity_level> >::record_pump(boost::log::v2s_mt_posix::sources::severity_logger_mt<boost::log::v2s_mt_posix::trivial::severity_level>&, boost::log::v2s_mt_posix::record&)':
/home/ubuntu/.vcpkg_cpptruths/installed/x64-linux/include/boost/log/sources/record_ostream.hpp:508: undefined reference to `boost::log::v2s_mt_posix::aux::stream_provider<char>::allocate_compound(boost::log::v2s_mt_posix::record&)'
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `boost::log::v2s_mt_posix::aux::record_pump<boost::log::v2s_mt_posix::sources::severity_logger_mt<boost::log::v2s_mt_posix::trivial::severity_level> >::auto_release::~auto_release()':
/home/ubuntu/.vcpkg_cpptruths/installed/x64-linux/include/boost/log/sources/record_ostream.hpp:493: undefined reference to `boost::log::v2s_mt_posix::aux::stream_provider<char>::release_compound(boost::log::v2s_mt_posix::aux::stream_provider<char>::stream_compound*)'
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `boost::log::v2s_mt_posix::sources::aux::severity_level<boost::log::v2s_mt_posix::trivial::severity_level>::set_value(boost::log::v2s_mt_posix::trivial::severity_level)':
/home/ubuntu/.vcpkg_cpptruths/installed/x64-linux/include/boost/log/sources/severity_feature.hpp:137: undefined reference to `boost::log::v2s_mt_posix::sources::aux::get_severity_level()'
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `boost::log::v2s_mt_posix::record boost::log::v2s_mt_posix::sources::basic_logger<char, boost::log::v2s_mt_posix::sources::severity_logger_mt<boost::log::v2s_mt_posix::trivial::severity_level>, boost::log::v2s_mt_posix::sources::multi_thread_model<boost::log::v2s_mt_posix::aux::light_rw_mutex> >::open_record_unlocked<boost::parameter::aux::tagged_argument_list_of_1<boost::parameter::aux::tagged_argument<boost::log::v2s_mt_posix::keywords::tag::severity, boost::log::v2s_mt_posix::trivial::severity_level const> > >(boost::parameter::aux::tagged_argument_list_of_1<boost::parameter::aux::tagged_argument<boost::log::v2s_mt_posix::keywords::tag::severity, boost::log::v2s_mt_posix::trivial::severity_level const> > const&)':
/home/ubuntu/.vcpkg_cpptruths/installed/x64-linux/include/boost/log/sources/basic_logger.hpp:260: undefined reference to `boost::log::v2s_mt_posix::core::open_record(boost::log::v2s_mt_posix::attribute_set const&)'
/usr/bin/ld: CMakeFiles/boost_log_trouble.dir/main.cpp.o: in function `boost::log::v2s_mt_posix::core::push_record(boost::log::v2s_mt_posix::record&&)':
/home/ubuntu/.vcpkg_cpptruths/installed/x64-linux/include/boost/log/core/core.hpp:308: undefined reference to `boost::log::v2s_mt_posix::core::push_record_move(boost::log::v2s_mt_posix::record&)'
collect2: error: ld returned 1 exit status
ninja: build stopped: subcommand failed.

Build failed.
```