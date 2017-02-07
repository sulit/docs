Flatpak Command Reference
=========================

Version 0.6.13

Flatpak comes with a rich commandline interface.

Table of Contents

flatpak install — Install an application or runtime
flatpak update — Update an application or runtime
flatpak uninstall — Uninstall an application or runtime
flatpak list — List installed applications and/or runtimes
flatpak info — Show information about installed application and/or runtime
flatpak run — Run an application
flatpak override — Override application requirements
flatpak enter — Enter an application
flatpak document-export — Export a file to a sandboxed application
flatpak document-unexport — Stop exporting a file
flatpak document-info — Show information about exported files
flatpak document-list — List exported files
flatpak remote-add — Add a remote repository
flatpak remote-modify — Modify a remote repository
flatpak remote-delete — Delete a remote repository
flatpak remote-list — List remote repositories
flatpak remote-ls — Show available runtimes and applications
flatpak build-init — Initialize a build directory
flatpak build — Build in a directory
flatpak build-finish — Finalize a build directory
flatpak build-export — Create a repository from a build directory
flatpak build-bundle — Create a single-file bundle from a local repository
flatpak build-import-bundle — Import a file bundle into a local repository
flatpak build-update-repo — Create a repository from a build directory
flatpak build-sign — Sign an application or runtime
flatpak-builder — Help build application dependencies
flatpak metadata — Information about an application or runtime
flatpakrepo — Reference to a remote
flatpakref — Reference to a remote for an application or runtime
flatpak make-current — Make a specific version of an app current

Name

flatpak-install — Install an application or runtime
Synopsis

flatpak install [OPTION...] REMOTE REF...

flatpak install [OPTION...] [ --bundle | --from ] FILENAME
Description

Installs an application or runtime. REMOTE must name an existing remote and REF is a reference to the application or runtime to install.

Each REF arguments is a full or partial indentifier in the flatpak ref format, which looks like "(app|runtime)/ID/ARCH/BRANCH". All elements except ID are optional and can be left out, including the slashes, so most of the time you need only specify ID. Any part left out will be matched against what is in the remote, and if there are multiple matches an error message will list the alternatives.

By default this looks for both apps and runtime with the given REF in the specified REMOTE , but you can limit this by using the --app or --runtime option, or by supplying the initial element in the REF.

Note that flatpak allows one to have multiple branches of an application and runtimes installed and used at the same time. However, only version of an application one can be current, meaning its exported files (for instance desktop files and icons) are visible to the host. The last installed version is made current by default, but you can manually change with make-current.

Unless overridden with the --user option, this command creates a system-wide installation.

The alternative form of the command installs an application from a single-file bundle or a flatpakref file instead of a configured remote. Bundles can be created with the flatpak build-bundle command, flatpakref files are simple references to a remote repo for an application.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--bundle

    Install from a bundle file instead of a configured remote. 
--from

    Install from a flatpakref file instead of a configured remote. 
--user

    Create a per-user installation. 
--system

    Create a system-wide installation. 
--arch=ARCH

    The default architecture to install for, if not given explicitly in the REF . 
--subpath=PATH

    Install only a subpath of the ref. This is mainly used to install a subset of locales. This can be added multiple times to install multiple subpaths., 
--no-deploy

    Download the latest version, but don't deploy it. 
--no-pull

    Don't download the latest version, deploy whatever is locally available. 
--no-related

    Don't download related extensions, such as the locale data. 
--no-deps

    Don't verify runtime dependencies when installing. 
--app

    Assume that all REF s are apps if not explicitly specified. 
--runtime

    Assume that all REF s are runtimes if not explicitly specified. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user install test-repo org.gnome.GEdit
See also

flatpak(1), flatpak-update(1), flatpak-list(1), flatpak-build-bundle(1), flatpak-flatpakref(1)
Name

flatpak-update — Update an application or runtime
Synopsis

flatpak update [OPTION...] [REF...]
Description

Updates applications and runtimes. REF is a reference to the application or runtime to install. If no REF is given, everything is updated.

Each REF arguments is a full or partial indentifier in the flatpak ref format, which looks like "(app|runtime)/ID/ARCH/BRANCH". All elements except ID are optional and can be left out, including the slashes, so most of the time you need only specify ID. Any part left out will be matched against what is installed, and if there are multiple matches an error message will list the alternatives.

By default this looks for both apps and runtime with the given REF in the specified REMOTE , but you can limit this by using the --app or --runtime option, or by supplying the initial element in the REF.

Normally, this command updates the application to the tip of its branch. But it is possible to check out another commit, with the --commit option.

Note that updating a runtime is different from installing a different branch, and runtime updates are expected to keep strict compatibility. If an application update does cause a problem, it is possible to go back to the previous version, with the --commit option.

Unless overridden with the --user option, this command updates a system-wide installation.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--user

    Update a per-user installation. 
--system

    Update a system-wide installation. 
--arch=ARCH

    The architecture to update for. 
--subpath=PATH

    Install only a subpath of the ref. This is mainly used to install a subset of locales. This can be added multiple times to install multiple subpaths. If this is not specified the subpaths specified at install time are reused. 
--commit=COMMIT

    Update to this commit, instead of the tip of the branch. 
--no-deploy

    Download the latest version, but don't deploy it. 
--no-pull

    Don't download the latest version, deploy it whatever is locally available. 
--no-related

    Don't download related extensions, such as the locale data. 
--no-deps

    Don't update or install runtime dependencies when installing. 
--app

    Only look for an app with the given name. 
--appstream

    Update appstream for the remote. 
--runtime

    Only look for an runtime with the given name. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user update org.gnome.GEdit
See also

flatpak(1), flatpak-install(1), flatpak-list(1)
Name

flatpak-uninstall — Uninstall an application or runtime
Synopsis

flatpak uninstall [OPTION...] [REF...]
Description

Uninstalls an application or runtime. REF is a reference to the application or runtime to install. If no REF is given, everything is updated.

Each REF arguments is a full or partial indentifier in the flatpak ref format, which looks like "(app|runtime)/ID/ARCH/BRANCH". All elements except ID are optional and can be left out, including the slashes, so most of the time you need only specify ID. Any part left out will be matched against what is installed, and if there are multiple matches an error message will list the alternatives.

By default this looks for both installed apps and runtime with the given NAME , but you can limit this by using the --app or --runtime option.

Normally, this command removes the ref for this application/runtime from the local OSTree repository and purges and objects that are no longer needed to free up disk space. If the same application is later reinstalled, the objects will be pulled from the remote repository again. The --keep-ref option can be used to prevent this.

If all branches of the application/runtime are removed, this command also purges the data directory for the application.

Unless overridden with the --user option, this command updates a system-wide installation.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--keep-ref

    Keep the ref for the application and the objects belonging to it in the local repository. 
--user

    Remove a per-user installation. 
--system

    Remove a system-wide installation. 
--arch=ARCH

    The architecture to uninstall, instead of the architecture of the host system. 
--app

    Only look for an app with the given name. 
--runtime

    Only look for an runtime with the given name. 
--no-related

    Don't uninstall related extensions, such as the locale data. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user uninstall org.gnome.GEdit
Name

flatpak-list — List installed applications and/or runtimes
Synopsis

flatpak list [OPTION...]
Description

Lists the names of the installed applications and/or runtime.

By default, both per-user and system-wide installations are shown. Use the --user or --system options to change this.

By default this lists the installed apps, but you can change this by using the --app or --runtime option.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--user

    List per-user installations. 
--system

    List system-wide installations. 
--arch=ARCH

    List installations for this architecture. 
--show-details

    Show arches and branches, in addition to the application names. 
--app

    List applications. 
--runtime

    List runtimes. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user list

org.gnome.Builder
org.freedesktop.glxgears
org.gnome.MyApp
org.gnome.GEdit

See also

flatpak(1), flatpak-install(1), flatpak-update(1)
Name

flatpak-info — Show information about installed application and/or runtime
Synopsis

flatpak info [OPTION...] NAME [BRANCH]
Description

Show info about and installed application and/or runtime.

By default, both per-user and system-wide installations are queried. Use the --user or --system options to change this.

By default this queries the installed apps and runtimes, but you can limit this by using the --app or --runtime option.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--user

    Query per-user installations. 
--system

    Query system-wide installations. 
--app

    Query for applications. 
--runtime

    Query for runtimes. 
-r, --show-ref

    Show the installed ref. 
-o, --show-origin

    Show the remote the ref is installed from. 
-c, --show-commit

    Show the installed commit id. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user list

org.gnome.Builder
org.freedesktop.glxgears
org.gnome.MyApp
org.gnome.GEdit

See also

flatpak(1), flatpak-install(1), flatpak-update(1)
Name

flatpak-run — Run an application
Synopsis

flatpak run [OPTION...] APP [ARG...]
Description

Runs an application in a sandboxed environment. APP must name an installed application. Extra arguments are passed on to the application.

flatpak creates a sandboxed environment for the application to run in by mounting the right runtime at /usr and a writable directory at /var, whose content is preserved between application runs. The application itself is mounted at /app.

The details of the sandboxed environment are controlled by the application metadata and various options like --share and --socket that are passed to the run command: Access is allowed if it was requested either in the application metadata file or with an option and the user hasn't overridden it.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 
--arch=ARCH

    The architecture to install for. 
--command=COMMAND

    The command to run instead of the one listed in the application metadata. 
--branch=BRANCH

    The branch to use. 
-d, --devel

    Use the devel runtime that is specified in the application metadata instead of the regular runtime, and use a seccomp profile that is less likely to break development tools. 
--runtime=RUNTIME

    Use this runtime instead of the one that is specified in the application metadata. This is a full tuple, like for example org.freedesktop.Sdk/x86_64/1.2 , but partial tuples are allowed. Any empty or missing parts are filled in with the corresponding values specified by the app. 
--runtime-version=VERSION

    Use this version of the runtime instead of the one that is specified in the application metadata. This overrides any version specified with the --runtime option. 
--share=SUBSYSTEM

    Share a subsystem with the host session. This overrides the Context section from the application metadata. SUBSYSTEM must be one of: network, ipc. This option can be used multiple times. 
--unshare=SUBSYSTEM

    Don't share a subsystem with the host session. This overrides the Context section from the application metadata. SUBSYSTEM must be one of: network, ipc. This option can be used multiple times. 
--socket=SOCKET

    Expose a well known socket to the application. This overrides to the Context section from the application metadata. SOCKET must be one of: x11, wayland, pulseaudio, system-bus, session-bus. This option can be used multiple times. 
--nosocket=SOCKET

    Don't expose a well known socket to the application. This overrides to the Context section from the application metadata. SOCKET must be one of: x11, wayland, pulseaudio, system-bus, session-bus. This option can be used multiple times. 
--device=DEVICE

    Expose a device to the application. This overrides to the Context section from the application metadata. DEVICE must be one of: dri, kvm, all. This option can be used multiple times. 
--nodevice=DEVICE

    Don't expose a device to the application. This overrides to the Context section from the application metadata. DEVICE must be one of: dri, kvm, all. This option can be used multiple times. 
--allow=FEATURE

    Allow access to a specific feature. This overrides to the Context section from the application metadata. FEATURE must be one of: devel, multiarch. This option can be used multiple times. 
--disallow=FEATURE

    Disallow access to a specific feature. This overrides to the Context section from the application metadata. FEATURE must be one of: devel, multiarch. This option can be used multiple times. 
--filesystem=FS

    Allow the application access to a subset of the filesystem. This overrides to the Context section from the application metadata. FS can be one of: home, host, xdg-desktop, xdg-documents, xdg-download xdg-music, xdg-pictures, xdg-public-share, xdg-templates, xdg-videos, xdg-run, an absolute path, or a homedir-relative path like ~/dir or paths relative to the xdg dirs, like xdg-download/subdir. This option can be used multiple times. 
--env=VAR=VALUE

    Set an environment variable in the application. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--own-name=NAME

    Allow the application to own the well known name NAME on the session bus. If NAME ends with .*, it allows the application to own all matching names. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--talk-name=NAME

    Allow the application to talk to the well known name NAME on the session bus. If NAME ends with .*, it allows the application to talk to all matching names. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--system-own-name=NAME

    Allow the application to own the well known name NAME on the system bus. If NAME ends with .*, it allows the application to own all matching names. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--system-talk-name=NAME

    Allow the application to talk to the well known name NAME on the system bus. If NAME ends with .*, it allows the application to talk to all matching names. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--persist=FILENAME

    If the application doesn't have access to the real homedir, make the (homedir-relative) path FILENAME a bind mount to the corresponding path in the per-application directory, allowing that location to be used for persistent data. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--log-session-bus

    Log session bus traffic. This can be useful to see what access you need to allow in your D-Bus policy. 
--log-system-bus

    Log system bus traffic. This can be useful to see what access you need to allow in your D-Bus policy. 

Examples

$ flatpak run org.gnome.GEdit

$ flatpak run --devel --command=bash org.gnome.Builder
See also

flatpak(1), flatpak-override(1), flatpak-enter(1)
Name

flatpak-override — Override application requirements
Synopsis

flatpak override [OPTION...] APP
Description

Overrides the application specified runtime requirements. This can be used to grant a sandboxed application more or less resources than it requested.

By default the application gets access to the resources it requested when it is started. But the user can override it on a particular instance by specifying extra arguments to flatpak run, or every time by using flatpak override.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--share=SUBSYSTEM

    Share a subsystem with the host session. This overrides the Context section from the application metadata. SUBSYSTEM must be one of: network, ipc. This option can be used multiple times. 
--unshare=SUBSYSTEM

    Don't share a subsystem with the host session. This overrides the Context section from the application metadata. SUBSYSTEM must be one of: network, ipc. This option can be used multiple times. 
--socket=SOCKET

    Expose a well-known socket to the application. This overrides to the Context section from the application metadata. SOCKET must be one of: x11, wayland, pulseaudio, system-bus, session-bus. This option can be used multiple times. 
--nosocket=SOCKET

    Don't expose a well-known socket to the application. This overrides to the Context section from the application metadata. SOCKET must be one of: x11, wayland, pulseaudio, system-bus, session-bus. This option can be used multiple times. 
--device=DEVICE

    Expose a device to the application. This overrides to the Context section from the application metadata. DEVICE must be one of: dri, kvm, all. This option can be used multiple times. 
--nodevice=DEVICE

    Don't expose a device to the application. This overrides to the Context section from the application metadata. DEVICE must be one of: dri, kvm, all. This option can be used multiple times. 
--filesystem=FS

    Allow the application access to a subset of the filesystem. This overrides to the Context section from the application metadata. FS can be one of: home, host, xdg-desktop, xdg-documents, xdg-download xdg-music, xdg-pictures, xdg-public-share, xdg-templates, xdg-videos, xdg-run, an absolute path, or a homedir-relative path like ~/dir or paths relative to the xdg dirs, like xdg-download/subdir. This option can be used multiple times. 
--env=VAR=VALUE

    Set an environment variable in the application. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--own-name=NAME

    Allow the application to own the well-known name NAME on the session bus. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--talk-name=NAME

    Allow the application to talk to the well-known name NAME on the session bus. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--system-own-name=NAME

    Allow the application to own the well known name NAME on the system bus. If NAME ends with .*, it allows the application to own all matching names. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--system-talk-name=NAME

    Allow the application to talk to the well known name NAME on the system bus. If NAME ends with .*, it allows the application to talk to all matching names. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--persist=FILENAME

    If the application doesn't have access to the real homedir, make the (homedir-relative) path FILENAME a bind mount to the corresponding path in the per-application directory, allowing that location to be used for persistent data. This overrides to the Context section from the application metadata. This option can be used multiple times. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak override --nosocket=wayland org.gnome.GEdit

$ flatpak override --filesystem=home org.mozilla.Firefox
See also

flatpak(1), flatpak-run(1)
Name

flatpak-enter — Enter an application
Synopsis

flatpak enter [OPTION...] MONITORPID COMMAND [ARG...]
Description

Enter a running sandbox. SANDBOXEDPID must be the pid of a process running in a flatpak sandbox. COMMAND is the command to run in the sandbox. Extra arguments are passed on to the command.

This creates a new process within the running sandbox, with the same environment. This is useful when you want to debug a problem with a running application.

This command requires extra privileges, so must be run as root or via e.g. sudo.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak enter 15345 sh
See also

flatpak(1), flatpak-run(1)
Name

flatpak-document-export — Export a file to a sandboxed application
Synopsis

flatpak document-export [OPTION...] FILE
Description

Creates a document id for a local file that can be exposed to sandboxed applications, allowing them access to files that they would not otherwise see. The exported files are exposed in a fuse filesystem at /run/user/$UID/doc/.

This command also lets you modify the per-application permissions of the documents, granting or revoking access to the file on a per-application basis.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--unique

    Don't reuse an existing document id for the file. This makes it safe to later remove the document when you're finished with it. 
--transient

    The document will only exist for the length of the session. This is useful for temporary grants. 
--app=APPID

    Grant read access to the specified application. The --allow and --forbid options can be used to grant or remove additional privileges. This option can be used multiple times. 
--allow-read

    Grant read access to the applications specified with --app. This defaults to TRUE. 
--forbid-read

    Revoke read access for the applications specified with --app. 
--allow-write

    Grant write access to the applications specified with --app. 
--forbid-write

    Revoke write access for the applications specified with --app. 
--allow-delete

    Grant the ability to remove the document from the document portal to the applications specified with --app. 
--forbid-delete

    Revoke the ability to remove the document from the document portal from the applications specified with --app. 
--allow-grant-permission

    Grant the ability to grant further permissions to the applications specified with --app. 
--forbid-grant-permission

    Revoke the ability to grant further permissions for the applications specified with --app. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak document-export --app=org.gnome.GEdit ~/test.txt

/run/user/1000/doc/e52f9c6a/test.txt

See also

flatpak(1), flatpak-document-unexport(1), flatpak-document-info(1), flatpak-document-list(1)
Name

flatpak-document-unexport — Stop exporting a file
Synopsis

flatpak document-export [OPTION...] FILE
Description

Removes the document id for the file from the document portal. This will make the document unavailable to all sandboxed applications.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

See also

flatpak(1), flatpak-document-export(1), flatpak-document-info(1), flatpak-document-list(1)
Name

flatpak-document-info — Show information about exported files
Synopsis

flatpak document-info [OPTION...] FILE
Description

Shows information about an exported file, such as the document id, the fuse path, the original location in the filesystem, and the per-application permissions.

FILE can either be a file in the fuse filesystem at /run/user/$UID/doc/, or a file anywhere else.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak document-info ~/Sources/gtk/gail-3.0.pc

id: dd32c34a
path: /run/user/1000/doc/dd32c34a/gail-3.0.pc
origin: /home/mclasen/Sources/gtk/gail-3.0.pc
permissions:
        org.gnome.gedit read, write

See also

flatpak(1), flatpak-document-export(1), flatpak-document-unexport(1), flatpak-document-list(1)
Name

flatpak-document-list — List exported files
Synopsis

flatpak document-list [OPTION...] [APPID]
Description

Lists exported files, with their document id and the full path to their origin. If an APPID is specified, only the files exported to this app are listed.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

See also

flatpak(1), flatpak-document-export(1), flatpak-document-unexport(1), flatpak-document-info(1)
Name

flatpak-remote-add — Add a remote repository
Synopsis

flatpak remote-add [OPTION...] NAME LOCATION
Description

Adds a remote repository to the flatpak repository configuration. NAME is the name for the new remote, and LOCATION is the url or pathname for the repository.

Unless overridden with the --user option, this command changes the system-wide configuration.

The alternative form of the command adds a remote from a flatpakrepo file.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--from

    Add from a flatpakrepo file (local or http uri) instead of from commandline arguments. This means the LOCATION argument specifies the filename/uri of a flatpakref rather than a repo url. 
--user

    Modify the per-user configuration. 
--system

    Modify the system-wide configuration. 
--no-gpg-verify

    Disable GPG verification for the added remote. 
--prio=PRIO

    Set the priority for the remote. Default is 1, higher is more prioritized. This is mainly used for graphical installation tools. 
--no-enumerate

    Mark the remote as not enumerated. This means the remote will not be used to list applications, for instance in graphical installation tools. 
--no-use-for-deps

    Mark the remote as not to be used for automatic runtime dependency resolution. 
--if-not-exists

    Do nothing if the provided remote already exists. 
--disable

    Disable the added remote. 
--title=TITLE

    A title for the remote, e.g. for display in a UI. 
--default-branch=BRANCH

    A default branch to for the remote, mainly for use in a UI. 
--gpg-import=FILE

    Import gpg keys from the specified keyring file as trusted for the new remote. If the file is - the keyring is read from standard input. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user remote-add --no-gpg-verify test-repo https://people.gnome.org/~alexl/gnome-sdk/repo/
See also

flatpak(1), flatpak-modify-remote(1), flatpak-delete-remote(1), flatpak-list-remotes(1), flatpak-flatpakrepo(1)
Name

flatpak-remote-modify — Modify a remote repository
Synopsis

flatpak remote-modify [OPTION...] NAME
Description

Modifies options for an existing remote repository in the flatpak repository configuration. NAME is the name for the remote.

Unless overridden with the --user option, this command changes the system-wide configuration.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--user

    Modify the per-user configuration. 
--system

    Modify the system-wide configuration. 
--no-gpg-verify

    Disable GPG verification for the added remote. 
--gpg-verify

    Enable GPG verification for the added remote. 
--prio=PRIO

    Set the priority for the remote. Default is 1, higher is more prioritized. This is mainly used for graphical installation tools. 
--no-enumerate

    Mark the remote as not enumerated. This means the remote will not be used to list applications, for instance in graphical installation tools. 
--no-use-for-deps

    Mark the remote as not to be used for automatic runtime dependency resolution. 
--disable

    Disable the remote. Disabled remotes will not be automatically updated from. 
--enable

    Enable the remote. 
--enumerate

    Mark the remote as enumerated. This means the remote will be used to list applications, for instance in graphical installation tools. 
--use-for-deps

    Mark the remote as to be used for automatic runtime dependency resolution. 
--title=TITLE

    A title for the remote, e.g. for display in a UI. 
--default-branch=BRANCH

    A default branch to for the remote, mainly for use in a UI. 
--update-metadata

    A default branch to for the remote, mainly for use in a UI.

    Update the remote's extra metadata from the OSTree repository's summary file. Only xa.title and xa.default-branch are supported at the moment. 
--gpg-import=FILE

    Import gpg keys from the specified keyring file as trusted for the new remote. If the file is - the keyring is read from standard input. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user remote-modify --no-gpg-verify test-repo
See also

flatpak(1), flatpak-remote-add(1), flatpak-remote-delete(1), flatpak-remote-list(1)
Name

flatpak-remote-delete — Delete a remote repository
Synopsis

flatpak remote-delete [OPTION...] NAME
Description

Removes a remote repository from the flatpak repository configuration. NAME is the name of an existing remote.

Unless overridden with the --user option, this command changes the system-wide configuration.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--user

    Modify the per-user configuration. 
--system

    Modify the system-wide configuration. 
--force

    Remove remote even if its in use by installed apps or runtimes. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user remote-delete dried-raisins
See also

flatpak(1), flatpak-add-remote(1), flatpak-modify-remote(1), flatpak-list-remotes(1)
Name

flatpak-remote-list — List remote repositories
Synopsis

flatpak remote-list [OPTION...]
Description

Lists the known remote repositories, in priority order.

By default, both per-user and system-wide installations are shown. Use the --user or --system options to change this.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--user

    Show the per-user configuration. 
--system

    Show the system-wide configuration. 
--show-details

    Show more information each repository in addition to the name. 
--show-disabled

    Show disabled repos. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak remote-list --user --show-details

testrepo	Test Repository	 http://209.132.179.91/repo/ no-gpg-verify

See also

flatpak(1), flatpak-add-remote(1), flatpak-delete-remote(1)
Name

flatpak-remote-ls — Show available runtimes and applications
Synopsis

flatpak remote-ls [OPTION...] REMOTE
Description

Shows runtimes and applications that are available in the remote repository with the name REMOTE . You can find all configured remote repositories with flatpak remote-list.

Unless overridden with the --user option, this command uses the system-wide configuration.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--user

    Use the per-user configuration. 
--system

    Use the system-wide configuration. 
-d, --show-details

    Show arches, branches and commit ids, in addition to the names. 
--runtime

    Show only runtimes, omit applications. 
--app

    Show only applications, omit runtimes. 
--updates

    Show only those which have updates available. 
--arch=ARCH

    Show only those matching the specied architecture. By default, only supported architectures are shown. Use --arch=* to show all archtectures. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user remote-ls --only-apps testrepo

org.gnome.Builder
org.freedesktop.glxgears

See also

flatpak(1), flatpak-remote-list(1)
Name

flatpak-build-init — Initialize a build directory
Synopsis

flatpak build-init [OPTION...] DIRECTORY APPNAME SDK RUNTIME [BRANCH]
Description

Initializes a directory for building an application. DIRECTORY is the name of the directory. APPNAME is the application id of the app that will be built. SDK and RUNTIME specify the sdk and runtime that the application should be built against and run in.

The result of this command is that a metadata file is created inside the given directory. Additionally, empty files and var subdirectories are created.

It is an error to run build-init on a directory that has already been initialized as a build directory.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--arch=ARCH

    The architecture to use. 
-v, --var=RUNTIME

    Initialize var from the named runtime. 
-w, --writable-sdk

    Initialize /usr with a copy of the sdk, which is writable during flatpak build. This can be used if you need to install build tools in /usr during the build. This is stored in the usr subdirectory of the app dir, but will not be part of the final app. 
--tag=TAG

    Add a tag to the metadata file. This option can be used multiple times. 
--sdk-extension=EXTENSION

    When using --writable-sdk, in addition to the sdk, also install the specified extension. This option can be used multiple times. 
--sdk-dir

    Specify a custom subdirectory to use instead of usr for --writable-sdk. 
--update

    Re-initialize the sdk and var, don't fail if already initialized. 
--base=APP

    Initialize the application with files from another specified application. 
--base-version=VERSION

    Specify the version to use for --base. If not specified, will default to "master". 
--base-extension=EXTENSION

    When using --base, also install the specified extension from the app. This option can be used multiple times. 
--verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak build-init /build/my-app org.gnome.Sdk org.gnome.Platform 3.16
See also

flatpak(1), flatpak-build(1), flatpak-build-finish(1), flatpak-build-export(1)
Name

flatpak-build — Build in a directory
Synopsis

flatpak build [OPTION...] DIRECTORY [COMMAND [ARG...]]
Description

Runs a build command in a directory. DIRECTORY must have been initialized with flatpak build-init.

The sdk that is specified in the metadata file in the directory is mounted at /usr and the files and var subdirectories are mounted at /app and /var, respectively. They are writable, and their contents are preserved between build commands, to allow accumulating build artifacts there.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 
-r, --runtime

    Use the non-devel runtime that is specified in the application metadata instead of the devel runtime. 
--bind-mount=DEST=SOURCE

    Add a custom bind mount in the build namespace. Can be specified multiple times. 
--build-dir=PATH

    Start the build in this directory (default is in the current directory). 
--share=SUBSYSTEM

    Share a subsystem with the host session. This overrides the Context section from the application metadata. SUBSYSTEM must be one of: network, ipc. This option can be used multiple times. 
--unshare=SUBSYSTEM

    Don't share a subsystem with the host session. This overrides the Context section from the application metadata. SUBSYSTEM must be one of: network, ipc. This option can be used multiple times. 
--socket=SOCKET

    Expose a well-known socket to the application. This overrides to the Context section from the application metadata. SOCKET must be one of: x11, wayland, pulseaudio, system-bus, session-bus. This option can be used multiple times. 
--nosocket=SOCKET

    Don't expose a well-known socket to the application. This overrides to the Context section from the application metadata. SOCKET must be one of: x11, wayland, pulseaudio, system-bus, session-bus. This option can be used multiple times. 
--device=DEVICE

    Expose a device to the application. This overrides to the Context section from the application metadata. DEVICE must be one of: dri, kvm, all. This option can be used multiple times. 
--nodevice=DEVICE

    Don't expose a device to the application. This overrides to the Context section from the application metadata. DEVICE must be one of: dri, kvm, all. This option can be used multiple times. 
--filesystem=FILESYSTEM[:ro]

    Allow the application access to a subset of the filesystem. This overrides to the Context section from the application metadata. FILESYSTEM can be one of: home, host, xdg-desktop, xdg-documents, xdg-download xdg-music, xdg-pictures, xdg-public-share, xdg-templates, xdg-videos, an absolute path, or a homedir-relative path like ~/dir. The optional :ro suffix indicates that the location will be read-only. This option can be used multiple times. 
--nofilesystem=FILESYSTEM

    Remove access to the specified subset of the filesystem from the application. This overrides to the Context section from the application metadata. FILESYSTEM can be one of: home, host, xdg-desktop, xdg-documents, xdg-download xdg-music, xdg-pictures, xdg-public-share, xdg-templates, xdg-videos, an absolute path, or a homedir-relative path like ~/dir. This option can be used multiple times. 
--env=VAR=VALUE

    Set an environment variable in the application. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--own-name=NAME

    Allow the application to own the well-known name NAME on the session bus. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--talk-name=NAME

    Allow the application to talk to the well-known name NAME on the session bus. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--system-own-name=NAME

    Allow the application to own the well-known name NAME on the system bus. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--system-talk-name=NAME

    Allow the application to talk to the well-known name NAME on the system bus. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--persist=FILENAME

    If the application doesn't have access to the real homedir, make the (homedir-relative) path FILENAME a bind mount to the corresponding path in the per-application directory, allowing that location to be used for persistent data. This overrides to the Context section from the application metadata. This option can be used multiple times. 

Examples

$ flatpak build /build/my-app rpmbuild my-app.src.rpm
See also

flatpak(1), flatpak-build-init(1), flatpak-build-finish(1), flatpak-build-export(1)
Name

flatpak-build-finish — Finalize a build directory
Synopsis

flatpak build-finish [OPTION...] DIRECTORY
Description

Finalizes a build directory, to prepare it for exporting. DIRECTORY is the name of the directory.

The result of this command is that desktop files, icons and D-Bus service files from the files subdirectory are copied to a new export subdirectory. In the metadata file, the command key is set in the [Application] group, and the supported keys in the [Environment] group are set according to the options.

You should review the exported files and the application metadata before creating and distributing an application bundle.

It is an error to run build-finish on a directory that has not been initialized as a build directory, or has already been finalized.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--command=COMMAND

    The command to use. If this option is not specified, the first executable found in files/bin is used. 
--share=SUBSYSTEM

    Share a subsystem with the host session. This updates the [Context] group in the metadata. SUBSYSTEM must be one of: network, ipc. This option can be used multiple times. 
--unshare=SUBSYSTEM

    Don't share a subsystem with the host session. This updates the [Context] group in the metadata. SUBSYSTEM must be one of: network, ipc. This option can be used multiple times. 
--socket=SOCKET

    Expose a well known socket to the application. This updates the [Context] group in the metadata. SOCKET must be one of: x11, wayland, pulseaudio, system-bus, session-bus. This option can be used multiple times. 
--nosocket=SOCKET

    Don't expose a well known socket to the application. This updates the [Context] group in the metadata. SOCKET must be one of: x11, wayland, pulseaudio, system-bus, session-bus. This option can be used multiple times. 
--device=DEVICE

    Expose a device to the application. This updates the [Context] group in the metadata. DEVICE must be one of: dri, kvm, all. This option can be used multiple times. 
--nodevice=DEVICE

    Don't expose a device to the application. This updates the [Context] group in the metadata. DEVICE must be one of: dri, kvm, all. This option can be used multiple times. 
--allow=FEATURE

    Allow access to a specific feature. This updates the [Context] group in the metadata. FEATURE must be one of: devel, multiarch. This option can be used multiple times.

    The devel feature allows the application to access certain syscalls such as ptrace(), and perf_event_open().

    The multiarch feature allows the application to execute programs compiled for an ABI other than the one supported natively by the system. For example, for the x86_64 architecture, 32-bit x86 binaries will be allowed as well. 
--disallow=FEATURE

    Disallow access to a specific feature. This updates the [Context] group in the metadata. FEATURE must be one of: devel, multiarch. This option can be used multiple times. 
--filesystem=FS

    Allow the application access to a subset of the filesystem. This updates the [Context] group in the metadata. FS can be one of: home, host, xdg-desktop, xdg-documents, xdg-download xdg-music, xdg-pictures, xdg-public-share, xdg-templates, xdg-videos, xdg-run, an absolute path, or a homedir-relative path like ~/dir or paths relative to the xdg dirs, like xdg-download/subdir. This option can be used multiple times. 
--env=VAR=VALUE

    Set an environment variable in the application. This updates the [Environment] group in the metadata. This overrides to the Context section from the application metadata. This option can be used multiple times. 
--own-name=NAME

    Allow the application to own the well known name NAME on the session bus. If NAME ends with .*, it allows the application to own all matching names. This updates the [Session Bus Policy] group in the metadata. This option can be used multiple times. 
--talk-name=NAME

    Allow the application to talk to the well known name NAME on the session bus. If NAME ends with .*, it allows the application to talk to all matching names. This updates the [Session Bus Policy] group in the metadata. This option can be used multiple times. 
--system-own-name=NAME

    Allow the application to own the well known name NAME on the system bus. If NAME ends with .*, it allows the application to own all matching names. This updates the [System Bus Policy] group in the metadata. This option can be used multiple times. 
--system-talk-name=NAME

    Allow the application to talk to the well known name NAME on the system bus. If NAME ends with .*, it allows the application to talk to all matching names. This updates the [System Bus Policy] group in the metadata. This option can be used multiple times. 
--persist=FILENAME

    If the application doesn't have access to the real homedir, make the (homedir-relative) path FILENAME a bind mount to the corresponding path in the per-application directory, allowing that location to be used for persistent data. This updates the [Context] group in the metadata. This option can be used multiple times. 
--extra-data=NAME:SHA256:DOWNLOAD-SIZE:INSTALL-SIZE:URL

    Adds information about extra data uris to the app. These will be downloaded and verified by the client when the app is installed and placed in the /app/extra directory. You can also supply an /app/bin/apply_extra script that will be run after the files are downloaded. 
--no-exports

    Don't look for exports in the build. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak build-finish /build/my-app --socket=x11 --share=ipc

Exporting share/applications/gnome-calculator.desktop
Exporting share/dbus-1/services/org.gnome.Calculator.SearchProvider.service
More than one executable
Using gcalccmd as command
Please review the exported files and the metadata

See also

flatpak(1), flatpak-build-init(1), flatpak-build(1), flatpak-build-export(1)
Name

flatpak-build-export — Create a repository from a build directory
Synopsis

flatpak build-export [OPTION...] LOCATION DIRECTORY [BRANCH]
Description

Creates or updates a repository with an application build. LOCATION is the location of the repository. DIRECTORY must be a finalized build directory. If BRANCH is not specified, it is assumed to be "master".

If LOCATION exists, it is assumed to be an OSTree repository, otherwise a new OSTree repository is created at this location. The repository can be inspected with the ostree tool.

The contents of DIRECTORY are committed on the branch with name app/APPNAME/ARCH/BRANCH, where ARCH is the architecture of the runtime that the application is using. A commit filter is used to enforce that only the contents of the files/ and export/ subdirectories and the metadata file are included in the commit, anything else is ignored.

The repo-update command should be used to update repository metadata whenever application builds are added to a repository.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
-s, --subject=SUBJECT

    One line subject for the commit message. 
-b, --body=BODY

    Full description for the commit message. 
--arch=ARCH

    Specify the architecture component of the branch to export. Only host compatible architectures can be specified. 
--exclude=PATTERN

    Exclude files matching PATTERN from the commit. This option can be used multiple times. 
--include=PATTERN

    Don't exclude files matching PATTERN from the commit, even if they match the --export patterns. This option can be used multiple times. 
--metadata=FILENAME

    Use the specified filename as metadata in the exported app instead of the default file (called metadata). This is useful if you want to commit multiple things from a single build tree, typically used in combination with --files and --exclude. 
--files=SUBDIR

    Use the files in the specified subdirectory as the file contents, rather than the regular files directory. 
--update-appstream

    Run appstream-builder and to update the appstream branch after build. 
--no-update-summary

    Don't update the summary file after the new commit is added. This means the repository will not be useful for serving over http until build-repo-update has been run. This is useful is you want to do multiple repo operations before finally updating the summary. 
--gpg-sign=KEYID

    Sign the commit with this GPG key. This option can be used multiple times. 
--gpg-homedir=PATH

    GPG Homedir to use when looking for keyrings 
--runtime

    Export a runtime instead for an app (this uses the usr subdir as files). 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak build-export ~/repos/gnome-calculator/ ~/build/gnome-calculator/ org.gnome.Calculator

Commit: 9d0044ea480297114d03aec85c3d7ae3779438f9d2cb69d717fb54237acacb8c
Metadata Total: 605
Metadata Written: 5
Content Total: 1174
Content Written: 1
Content Bytes Written: 305

See also

ostree(1), flatpak(1), flatpak-build-init(1), flatpak-build(1), flatpak-build-finish(1), flatpak-build-sign(1), flatpak-repo-update(1)
Name

flatpak-build-bundle — Create a single-file bundle from a local repository
Synopsis

flatpak build-bundle [OPTION...] LOCATION FILENAME NAME [BRANCH]
Description

Creates a single-file named FILENAME for the application (or runtime) named NAME in the repository at LOCATION . If a BRANCH is specified, this branch of the application is used.

The format of the bundle file is that of an ostree static delta (against an empty base) with some flatpak specific metadata for the application icons and appdata.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--runtime

    Export a runtime instead of an application. 
--arch=ARCH

    The arch to create a bundle for. 
--repo-url=URL

    The URL for the repository from which the application can be updated. Installing the bundle will automatically configure a remote for this URL. 
--gpg-keys=FILE

    Add the GPG key from FILE (use - for stdin). 
--gpg-homedir=PATH

    GPG Homedir to use when looking for keyrings. 
--oci

    Export to an OCI image instead of a Flatpak bundle. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

See also

ostree(1), flatpak(1), flatpak-build-init(1), flatpak-build(1), flatpak-build-finish(1), flatpak-build-import-bundle(1), flatpak-repo-update(1)
Name

flatpak-build-import-bundle — Import a file bundle into a local repository
Synopsis

flatpak build-import-bundle [OPTION...] LOCATION FILENAME
Description

Imports a bundle from a file named FILENAME into the repository at LOCATION .

The format of the bundle file is that generated by build-bundle.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--ref=REF

    Override the ref specified in the bundle. 
--oci

    Import an OCI image instead of a Flatpak bundle. 
--update-appstream

    Run appstream-builder and to update the appstream branch after build. 
--no-update-summary

    Don't update the summary file after the new commit is added. This means the repository will not be useful for serving over http until build-repo-update has been run. This is useful is you want to do multiple repo operations before finally updating the summary. 
--gpg-sign=KEYID

    Sign the commit with this GPG key. This option can be used multiple times. 
--gpg-homedir=PATH

    GPG Homedir to use when looking for keyrings 
--version

    Print version information and exit. 

See also

ostree(1), flatpak(1), flatpak-build-bundle(1), flatpak-repo-update(1)
Name

flatpak-build-update-repo — Create a repository from a build directory
Synopsis

flatpak build-update-repo [OPTION...] LOCATION
Description

Updates repository metadata for the repository at LOCATION . This command generates an OSTree summary file that lists the contents of the repository. The summary is used by flatpak repo-contents and other commands to display the contents of remote repositories.

After this command, LOCATION can be used as the repository location for flatpak add-repo, either by exporting it over http, or directly with a file: url.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--title=TITLE

    A title for the repository, e.g. for display in a UI. The title is stored in the repository summary. 
--gpg-sign=KEYID

    Sign the commit with this GPG key. This option can be used multiple times. 
--gpg-homedir=PATH

    GPG Homedir to use when looking for keyrings 
--generate-static-deltas

    Generate static deltas for all references. This generates from-empty and delta static files that allow for faster download. 
--prune

    Remove unreferences objects in repo. 
--prune-depth

    Only keep at most this number of old versions for any particular ref. Default is -1 which means infinite. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

See also

ostree(1), flatpak(1), flatpak-repo-contents(1), flatpak-build-export(1)
Name

flatpak-build-sign — Sign an application or runtime
Synopsis

flatpak build-sign [OPTION...] LOCATION ID [BRANCH]
Description

Signs the commit for a specified application or runtime in a local repository. LOCATION is the location of the repository. ID is the name of the application, or runtime if --runtime is specified. If BRANCH is not specified, it is assumed to be "master".

Applications can also be signed during build-export, but it is sometimes useful to add additional signatures later.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--gpg-sign=KEYID

    Sign the commit with this GPG key. This option can be used multiple times. 
--gpg-homedir=PATH

    GPG Homedir to use when looking for keyrings 
--runtime

    Sign a runtime instead of an app. 
--arch=ARCH

    The architecture to use. 
-v, --verbose

    Print debug information during command processing. 
--ostree-verbose

    Print OSTree debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak build-export ~/repos/gnome-calculator/ ~/build/gnome-calculator/ org.gnome.Calculator

Commit: 9d0044ea480297114d03aec85c3d7ae3779438f9d2cb69d717fb54237acacb8c
Metadata Total: 605
Metadata Written: 5
Content Total: 1174
Content Written: 1
Content Bytes Written: 305

See also

ostree(1), flatpak(1), flatpak-build-export(1), flatpak-build(1),
Name

flatpak-builder — Help build application dependencies
Synopsis

flatpak-builder [OPTION...] DIRECTORY MANIFEST

flatpak-builder --run [OPTION...] DIRECTORY MANIFEST COMMAND

flatpak-builder --show-deps [OPTION...] MANIFEST
Description

flatpak-builder is a wrapper around the flatpak build command that automates the building of applications and their dependencies. It is one option you can use to build applications.

The goal of flatpak-builder is to push as much knowledge about how to build modules to the individual upstream projects. It does this by assuming that the modules adhere to the Build API specified at https://github.com/cgwalters/build-api. This essentially means that it follows the ./configure && make && make install scheme with an optional autogen script. If the upstream does not adhere to the API you can make it do so by adding patches and extra files.

An invocation of flatpak-builder proceeds in these stages, each being specified in detail in json format in MANIFEST :

    Download all sources

    Initialize the application directory with flatpak build-init

    Build and install each module with flatpak build

    Clean up the final build tree by removing unwanted files and e.g. stripping binaries

    Finish the application directory with flatpak build-finish

After this you will end up with a build of the application in DIRECTORY , which you can export to a repository with the flatpak build-export command. If you use the --repo option, flatpack-builder will do the export for you at the end of the build process. When flatpak-builder does the export, it also stores the manifest that was used for the build in /app/manifest.json. The manifest is 'resolved', i.e. git branch names are replaced by the actual commit IDs that were used in the build.

At each of the above steps flatpak caches the result, and if you build the same file again, it will start of at the first step where something changes. For instance the first version controlled source that had new commits added, or the first module where some changes to the MANIFEST file caused the build environment to change. This makes flatpak-builder very efficient for incremental builds.
Manifest format
Toplevel

The top level of the json file describes global attributes of the application, and how it can be build, and the list of modules that need to be built.

These are the properties that are accepted:

id or app-id (string)

    A string defining the application id.
branch (string)

    The branch of the application, defaults to master.
runtime (string)

    The name of the runtime that the application uses.
runtime-version (string)

    The version of the runtime that the application uses, defaults to master.
sdk (string)

    The name of the development runtime that the application builds with.
var (string)

    Initialize the (otherwise empty) writable /var in the build with a copy of this runtime.
metadata (string)

    Use this file as the base metadata file when finishing.
command (string)

    The filename or path to the main binary of the application. Note that this is really just a single file, not a commandline. If you want to pass arguments, install a shell script wrapper and use that as the command.
build-runtime (boolean)

    Build a new runtime instead of an application.
separate-locales (boolean)

    Separate out locale files and translations to an extension runtime. Defaults to true.
id-platform (string)

    When building a runtime sdk, also create a platform based on it with this id.
metadata-platform (string)

    The metadata file to use for the platform we create.
writable-sdk (boolean)

    If true, use a writable copy of the sdk for /usr. Defaults to true if --build-runtime is specified.
appstream-compose (boolean)

    Run appstream-compose during cleanup phase. Defaults to true.
sdk-extensions (array of strings)

    Install these extra sdk extensions in /usr.
platform-extensions (array of strings)

    Install these extra sdk extensions when creating the platform.
base (string)

    Start with the files from the specified application. This can be used to create applications that extend another application.
base-version (string)

    Use this specific version of the application specified in base. If unspecified, this uses the value specified in branch
base-extensions (array of strings)

    Install these extra extensions from the base application when initializing the application directory.
tags (array of strings)

    Add these tags to the metadata file.
build-options (object)

    Object specifying the build environment. See below for details.
modules (array of objects or string)

    An array of objects specifying the modules to be built in order. String members in the array are interpreted as the name of a separate json file that contains a module. See below for details.
cleanup (array of strings)

    An array of file patterns that should be removed at the end. Patterns starting with / are taken to be full pathnames (without the /app prefix), otherwise they just match the basename.
cleanup-commands (array of strings)

    An array of commandlines that are run during the cleanup phase.
cleanup-platform (array of strings)

    Extra files to clean up in the platform.
finish-args (array of strings)

    An array of arguments passed to the flatpak build-finish command.
rename-desktop-file (string)

    Any desktop file with this name will be renamed to a name based on id during the cleanup phase.
rename-appdata-file (string)

    Any appdata file with this name will be renamed to a name based on id during the cleanup phase.
rename-icon (string)

    Any icon with this name will be renamed to a name based on id during the cleanup phase.
copy-icon (boolean)

    If rename-icon is set, keep a copy of the old icon file.
desktop-file-name-prefix (string)

    This string will be prefixed to the Name key in the main application desktop file.
desktop-file-name-suffix (string)

    This string will be suffixed to the Name key in the main application desktop file.

Build Options

Build options specify the build environment of a module, and can be specified globally as well as per-module. Options can also be specified on a per-architecture basis using the arch property.

These are the properties that are accepted:

cflags (string)

    This is set in the environment variable CFLAGS during the build.
cxxflags (string)

    This is set in the environment variable CXXFLAGS during the build.
prefix (string)

    The build prefix for the modules (defaults to /app for applications and /usr for runtimes).
env (object)

    This is a dictionary defining environment variables to be set during the build.
build-args (array of strings)

    This is an array containing extra options to pass to flatpak build.
strip (boolean)

    If this is true (the default is false) then all ELF files will be stripped after install.
no-debuginfo (boolean)

    By default (if strip is not true) flatpak-builder extracts all debug info in ELF files to a separate files and puts this in an extension. If you want to disable this, set no-debuginfo to true.
arch (object)

    This is a dictionary defining for each arch a separate build options object that override the main one.

Module

Each module specifies a source that has to be separately built and installed. It contains the build options and a list of sources to download and extract before building.

Modules can be nested, in order to turn related modules on and off with a single key.

These are the properties that are accepted:

name (string)

    The name of the module, used in e.g. build logs. The name is also used for constructing filenames and commandline arguments, therefore using spaces or '/' in this string is a bad idea.
disabled (boolean)

    If true, skip this module
sources (array of objects)

    An array of objects defining sources that will be downloaded and extracted in order
config-opts (array of strings)

    An array of options that will be passed to configure
make-args (array of strings)

    An array of arguments that will be passed to make
make-install-args (array of strings)

    An array of arguments that will be passed to make install
rm-configure (boolean)

    If true, remove the configure script before starting build
no-autogen (boolean)

    Ignore the existence of an autogen script
no-parallel-make (boolean)

    Don't call make with arguments to build in parallel
no-python-timestamp-fix (boolean)

    Don't fix up the *.py[oc] header timestamps for ostree use.
cmake (boolean)

    Use cmake instead of configure
builddir (boolean)

    Use a build directory that is separate from the source directory
subdir (string)

    Build inside this subdirectory of the extracted sources
build-options (object)

    A build options object that can override global options
post-install (array of strings)

    An array of shell commands that are run after the install phase. Can for example clean up the install dir, or install extra files. 
cleanup (array of strings)

    An array of file patterns that should be removed at the end. Patterns starting with / are taken to be full pathnames (without the /app prefix), otherwise they just match the basename. Note that any patterns will only match files installed by this module. 
cleanup-platform (array of strings)

    Extra files to clean up in the platform.
modules (array of objects or strings)

    An array of objects specifying nested modules to be built before this one. String members in the array are interpreted as names of a separate json file that contains a module.

Sources

These contain a pointer to the source that will be extracted into the source directory before the build starts. They can be of several types, distinguished by the type property.
Archive sources (tar, zip)

type

    "archive"
path (string)

    The path of the archive
url (string)

    The URL of a remote archive that will be downloaded. This overrides path if both are specified.
sha256 (string)

    The sha256 checksum of the file, verified after download
strip-components (integer)

    The number of initial pathname components to strip during extraction. Defaults to 1.
dest (string)

    Directory inside the source dir where the archive will be extracted.

Git sources

type

    "git"
path (string)

    The path to a local checkout of the git repository. Due to how git-clone works, this will be much faster than specifying a URL of file:///...
url (string)

    URL of the git repository. This overrides path if both are specified.
branch (string)

    The branch/tag/commit to use from the git repository
dest (string)

    Directory inside the source dir where the repository will be checked out.

Bzr sources

type

    "bzr"
url (string)

    URL of the bzr repository
revision (string)

    A specific revision to use in the branch
dest (string)

    Directory inside the source dir where the repository will be checked out.

File sources

type

    "file"
path (string)

    The path of a local file that will be copied into the source dir
url (string)

    The URL of a remote file that will be downloaded and copied into the source dir. This overrides path if both are specified.
sha256 (string)

    The sha256 checksum of the file, verified after download. This is optional for local files.
dest-filename (string)

    Filename to use inside the source dir, default to the basename of path.
dest (string)

    Directory inside the source dir where the file will be copied.

Script sources

This is a way to create a shell (/bin/sh) script from an inline set of commands.

type

    "script"
commands (array of strings)

    An array of shell commands that will be put in a shellscript file
dest-filename (string)

    Filename to use inside the source dir, default to the basename of path.
dest (string)

    Directory inside the source dir where the file will be copied.

Shell sources

This is a way to create/modify the sources by running shell commands.

type

    "shell"
commands (array of strings)

    An array of shell commands that will be run during source extraction

Patch sources

type

    "patch"
path (string)

    The path of a patch file that will be applied in the source dir
strip-components (integer)

    The value of the -p argument to patch, defaults to 1.
dest (string)

    Directory inside the source dir where the patch will be applied.
use-git (boolean)

    Whether to use "git apply" rather than "patch" to apply the patch, required when the patch file contains binary diffs.

Options

The following options are understood:

-h, --help

    Show help options and exit. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 
--arch=ARCH

    Specify the machine architecture to build for. If no architecture is specified, the host architecture will be automatically detected. Only host compatible architectures can be specified. 
--disable-cache

    Don't look at the existing cache for a previous build, instead always rebuild modules. 
--disable-download

    Don't download any sources. This only works if some version of all sources are downloaded already. This is useful if you want to guarantee that no network i/o is done. However, the build will fail if some source is not locally available. 
--disable-updates

    Download missing sources, but don't update local mirrors of version control repos. This is useful to rebuild things but without updating git or bzr repositories from the remote repository. 
--run

    Run a command in a sandbox based on the build dir. This starts flatpak build, with some extra arguments to give the same environment as the build, and the same permissions the final app will have. The command to run must be the last argument passed to flatpak-builder, after the directory and the manifest. 
--show-deps

    List all the (local) files that the manifest depends on. 
--download-only

    Exit successfully after downloading the required sources. 
--build-only

    Don't do the cleanup and finish stages, which is useful if you want to build more things into the app. 
--finish-only

    Only do the cleanup, finish and export stages, picking up where a --build-only command left off. 
--require-changes

    Do nothing, leaving a non-existent DIRECTORY if nothing changes since last cached build. If this is not specified, the latest version from the cache will be put into DIRECTORY . 
--keep-build-dirs

    Don't remove the sources and build after having built and installed each module. This also creates a symlink to the build directory with a stable name ("build-modulename"). 
--ccache

    Enable use of ccache in the build (needs ccache in the sdk) 
--stop-at=MODULENAME

    Stop building at the specified module, ignoring all the following ones. This is useful for debugging and development. For instance, you can build all the dependencies, but stop at the main application so that you can then do a build from a pre-existing checkout. Implies --build-only. 
--repo=DIR

    When build is done, run export the result to this repository. 
-s, --subject=SUBJECT

    One line subject for the commit message. Used when exporting the build results. 
-b, --body=BODY

    Full description for the commit message. Used when exporting the build results. 
--gpg-sign=KEYID

    Sign the commit with this GPG key. Used when exporting the build results. This option can be used multiple times. 
--gpg-homedir=PATH

    GPG Homedir to use when looking for keyrings. Used when exporting the build results. 
--force-clean

    Erase the previous contents of DIRECTORY if it is not empty. 
--sandbox

    Disable the possibility to specify build-args that are passed to flatpak build. This means the build process can't break out of its sandbox, and is useful when building less trusted software. 
--allow-missing-runtimes

    Do not immediately fail if the sdk or platform runtimes are not installed on this system. Attempting to build any manifest modules will still fail if the sdk is missing, but may be useful for apps that install files without a sandbox build. 

Caching

flatpak-builder caches sources and partial build results in the .flatpak-builder subdirectory of the current directory. If you use --keep-build-dirs, build directories for each module are also stored here.

It is safe to remove the contents of the .flatpak-builder directory. This will force a full build the next time you build.
Examples

$ flatpak-builder my-app-dir manifest.json

Example manifest file:

{
    "id": "org.test.TestApp",
    "runtime": "org.freedesktop.Platform",
    "runtime-version": "1.2",
    "sdk": "org.freedesktop.Sdk",
    "command": "test",
    "clean": [ "/include", "*.la" ],
    "build-options" : {
        "cflags": "-O2 -g",
        "cxxflags": "-O2 -g",
        "env": {
            "V": "1"
        },
        "arch": {
            "x86_64": {
                "cflags": "-O3 -g",
            }
        }
    },
    "modules": [
        {
            "name": "pygobject",
            "config-opts": [ "--disable-introspection" ],
            "sources": [
                {
                    "type": "archive",
                    "url": "http://ftp.gnome.org/pub/GNOME/sources/pygobject/2.28/pygobject-2.28.6.tar.xz",
                    "sha256": "fb8a1d4f665130a125011659bd347c7339c944232163dbb9a34fd0686577adb8"
                },
                {
                    "type": "patch",
                    "path": "required-pygobject-fix.patch"
                },
                {
                    "type": "file",
                    "path": "pygobject-extra-file",
                    "dest-filename": "extra-file"
                }
            ]
        },
        {
            "name": "babl",
            "build-options" : { "cxxflags": "-O2 -g -std=c++11" },
            "cleanup": [ "/bin" ],
            "sources": [
                {
                    "type": "git",
                    "url": "git://git.gnome.org/babl"
                }
            ]
        },
        {
            "name": "testapp",
            "sources": [
                {
                    "type": "bzr",
                    "url": "lp:testapp"
                }
            ]
        }
    ]
}

See also

flatpak(1), flatpak-build-init(1), flatpak-build(1), flatpak-build-finish(1), flatpak-build-export(1)
Name

flatpak-metadata — Information about an application or runtime
Description

Flatpak uses metadata files to describe applications and runtimes. The metadata file for a deployed application or runtime is placed in the toplevel deploy directory. For example, the metadata for the locally installed application org.gnome.Calculator is in ~/.local/share/flatpak/app/org.gnome.Calculator/current/active/metadata.

Most aspects of the metadata configuration can be overridden when launching applications, either temporarily via options of the flatpak run command, or permanently with the flatpak override command.

A metadata file describing the effective configuration is available inside the running sandbox at /run/user/$UID/flatpak-info.
File format

The metadata file is using the same .ini file format that is used for systemd unit files or application .desktop files.
[Application] or [Runtime]

Metadata for applications starts with an [Application] group, metadata for runtimes with a [Runtime] group.

The following keys can be present in these groups:

name (string)

    The name of the application or runtime. This key is mandatory.
runtime (string)

    The fully qualified name of the runtime that is used by the application. This key is mandatory for applications.
sdk (string)

    The fully qualified name of the sdk that matches the runtime.
command (string)

    The command to run. Only relevant for applications.

[Context]

This group determines various system resources that may be shared with the application when it is run in a flatpak sandbox.

All keys in this group (and the group itself) are optional.

shared (list)

    List of subsystems to share with the host system. Possible subsystems: network, ipc. 
sockets (list)

    List of well-known sockets to make available in the sandbox. Possible sockets: x11, wayland, pulseaudio, session-bus, system-bus. When making a socket available, flatpak also sets well-known environment variables like DISPLAY or DBUS_SYSTEM_BUS_ADDRESS to let the application find sockets that are not in a fixed location. 
devices (list)

    List of devices to make available in the sandbox. Possible values: dri, kvm, all. 
filesystems (list)

    List of filesystem subsets to make available to the application. Possible values: home, host, xdg-desktop, xdg-documents, xdg-download xdg-music, xdg-pictures, xdg-public-share, xdg-templates, xdg-videos, xdg-run, an absolute path, or a homedir-relative path like ~/dir or paths relative to the xdg dirs, like xdg-download/subdir. The xdg-* arguments can also specify a subdirectory, such as xdg-pictures/screenshots. Each entry can have a suffix of :ro or :rw to indicate if the path should be shared read-only or read-write (default is read-write). 
persistent (list)

    List of homedir-relative paths to make available at the corresponding path in the per-application home directory, allowing the locations to be used for persistent data when the application does not have access to the real homedir. For instance making ".myapp" persistent would make "~/.myapp" in the sandbox a bind mount to "~/.var/app/org.my.App/.myapp", thus allowing an unmodified application to save data in the per-application location. 

[Session Bus Policy]

If the sockets key is not allowing full access to the D-Bus session bus, then flatpak provides filtered access.

The default policy for the session bus only allows the application to own its own application ID and subnames. For instance if the app is called "org.my.App", it can only own "org.my.App" and "org.my.App.*". Its also only allowed to talk to the bus itself (org.freedesktop.DBus) and the portal APIs APIs (bus names of the form org.freedesktop.portal.*).

Additionally the app is always allowed to reply to messages sent to it, and emit broadcast signals (but these will not reach other sandboxed apps unless they are allowed to talk to your app.

If the [Session Bus Policy] group is present, it provides policy for session bus access.

Each key in this group has the form of a D-Bus bus name or prefix thereof, for example org.gnome.SessionManager or org.freedesktop.portal.*

The possible values for entry are, in increasing order or access:

none

    The bus name or names in question is invisible to the application. 
see

    The bus name or names can be enumerated by the application. 
talk

    The application can send messages/ and receive replies and signals from the bus name or names. 
own

    The application can own the bus name or names (as well as all the above). 

[System Bus Policy]

If the sockets key is not allowing full access to the D-Bus system bus, then flatpak does not make the system bus available unless the [System Bus Policy] group is present and provides a policy for filtered access.

Entries in this group have the same form as for the [Session Bus Policy] group. However, the app has no permissions by default.
[Environment]

The [Environment] group specifies environment variables to set when running the application.

Entries in this group have the form VAR=VALUE where VAR is the name of an environment variable to set.
[Extension NAME]

Runtimes and applications can define extensions, which are optional, additional runtimes to be mounted at a specified location inside the sandbox when they are present on the system. Typical uses for extensions include translations for applications, or debuginfo for sdks. The name of the extension is specified as part of the group heading.

directory (string)

    The relative path at which the extension will be mounted in the sandbox. If the extension is for an application, the path is relative to /app, otherwise it is relative to /usr. This key is mandatory. 
version (string)

    The branch to use when looking for the extension. If this is not specified, it defaults to the branch of the application or runtime that the extension is for. 
subdirectories (boolean)

    If this key is set to true, then flatpak will look for extensions whose name is a prefix of the extension name, and mount them at the corresponding name below the subdirectory. 
no-autodownload (boolean)

    Whether to automatically download this extension when updating or installing a 'related' application or runtime. 
autodelete (boolean)

    Whether to automatically delete this extension when deleting a 'related' application or runtime. 

Example

[Application]
name=org.gnome.Calculator
runtime=org.gnome.Platform/x86_64/3.20
sdk=org.gnome.Sdk/x86_64/3.20
command=gnome-calculator

[Context]
shared=network;ipc;
sockets=x11;wayland;
filesystems=xdg-run/dconf;~/.config/dconf:ro;

[Session Bus Policy]
ca.desrt.dconf=talk

[Environment]
DCONF_USER_CONFIG_DIR=.config/dconf

[Extension org.gnome.Calculator.Locale]
directory=share/runtime/locale
subdirectories=true

[Extension org.gnome.Calculator.Debug]
directory=lib/debug

See also

flatpak(1), flatpak-run(1), flatpak-override(1)
Name

flatpak-flatpakrepo — Reference to a remote
Description

Flatpak uses flatpakrepo files to share information about remotes. The flatpakrepo file contains enough information to add the remote. Use the flatpak remote-add --from command to do so.

The filename extension commonly used for flatpakrepo files is .flatpakrepo.
File format

The flatpakrepo file is using the same .ini file format that is used for systemd unit files or application .desktop files.
[Flatpak Repo]

All the information is contained in the [Flatpak Repo] group.

The following keys can be present in this group:

Url (string)

    The url for the remote. This key is mandatory.
Title (string)

    The title of the remote. This should be a user-friendly name that can be displayed e.g. in an app store.
GPGKey (string)

    The base64-encoded gpg key for the remote.

Example

[Flatpak Repo]
Title=GEdit
Url=http://sdk.gnome.org/repo-apps/
GPGKey=mQENBFUUCGcBCAC/K9WeV4xCaKr3NKRqPXeY5mpaXAJyasLqCtrDx92WUgbu0voWrhohNAKpqizod2dvzc/XTxm3rHyIxmNfdhz1gaGhynU75Qw4aJVcly2eghTIl++gfDtOvrOZo/VuAq30f32dMIgHQdRwEpgCwz7WyjpqZYltPAEcCNL4MTChAfiHJeeiQ5ibystNBW8W6Ymf7sO4m4g5+/aOxI54oCOzD9TwBAe+yXcJJWtc2rAhMCjtyPJzxd0ZVXqIzCe1xRvJ6Rq7YCiMbiM2DQFWXKnmYQbj4TGNMnwNdAajCdrcBWEMSbzq7EzuThIJRd8Ky4BkEe1St6tuqwFaMZz+F9eXABEBAAG0KEdub21lIFNESyAzLjE2IDxnbm9tZS1vcy1saXN0QGdub21lLm9yZz6JATgEEwECACIFAlUUCGcCGwMGCwkIBwMCBhUIAgkKCwQWAgMBAh4BAheAAAoJEArkz6VV0VKBa5cH/0vXa31YgEjNk78gGFXqnQxdD1WYA87OYxDi189l4lA802EFTF4wCBuZyDOqdd5BhS3Ab0cR778DmZXRUP2gwe+1zTJypU2JMnDpkwJ4NK1VP6/tE4SAPrznBtmb76BKaWBqUfZ9Wq1zg3ugvqkZB/Exq+usypIOwQVp1KL58TrjBRda0HvRctzkNhr0qYAtkfLFe0GvksBp4vBm8uGwAx7fw/HbhIjQ9pekTwvB+5GwDPO/tSip/1bQfCS+XJB8Ffa04HYPLGedalnWBrwhYY+G/kn5Zh9L/AC8xeLwTJTHM212rBjPa9CWs9C6a57MSaeGIEHLC1hEyiJJ15w8jmY=

See also

flatpak(1), flatpak-remote-add(1), flatpak-flatpakref(5)
Name

flatpak-flatpakref — Reference to a remote for an application or runtime
Description

Flatpak uses flatpakref files to share information about a remote for a single application. The flatpakref file contains enough information to add the remote and install the application. Use the flatpak install --from command to do so.

The filename extension commonly used for flatpakref files is .flatpakref.

A flatpakref file can also refer to a remote for a runtime.
File format

The flatpakref file is using the same .ini file format that is used for systemd unit files or application .desktop files.
[Flatpak Ref]

All the information is contained in the [Flatpak Ref] group.

The following keys can be present in this group:

Name (string)

    The fully qualified name of the runtime that is used by the application. This key is mandatory.
Url (string)

    The url for the remote. This key is mandatory.
Branch (string)

    The name of the branch from which to install the application or runtime. If this key is not specified, the "master" branch is used.
Title (string)

    The title of the application or runtime. This should be a user-friendly name that can be displayed e.g. in an app store.
IsRuntime (boolean)

    Whether this file refers to a runtime. If this key is not specified, the file is assumed to refer to an application.
GPGKey (string)

    The base64-encoded gpg key for the remote.

Example

[Flatpak Ref]
Title=GEdit
Name=org.gnome.gedit
Branch=stable
Url=http://sdk.gnome.org/repo-apps/
IsRuntime=False
GPGKey=mQENBFUUCGcBCAC/K9WeV4xCaKr3NKRqPXeY5mpaXAJyasLqCtrDx92WUgbu0voWrhohNAKpqizod2dvzc/XTxm3rHyIxmNfdhz1gaGhynU75Qw4aJVcly2eghTIl++gfDtOvrOZo/VuAq30f32dMIgHQdRwEpgCwz7WyjpqZYltPAEcCNL4MTChAfiHJeeiQ5ibystNBW8W6Ymf7sO4m4g5+/aOxI54oCOzD9TwBAe+yXcJJWtc2rAhMCjtyPJzxd0ZVXqIzCe1xRvJ6Rq7YCiMbiM2DQFWXKnmYQbj4TGNMnwNdAajCdrcBWEMSbzq7EzuThIJRd8Ky4BkEe1St6tuqwFaMZz+F9eXABEBAAG0KEdub21lIFNESyAzLjE2IDxnbm9tZS1vcy1saXN0QGdub21lLm9yZz6JATgEEwECACIFAlUUCGcCGwMGCwkIBwMCBhUIAgkKCwQWAgMBAh4BAheAAAoJEArkz6VV0VKBa5cH/0vXa31YgEjNk78gGFXqnQxdD1WYA87OYxDi189l4lA802EFTF4wCBuZyDOqdd5BhS3Ab0cR778DmZXRUP2gwe+1zTJypU2JMnDpkwJ4NK1VP6/tE4SAPrznBtmb76BKaWBqUfZ9Wq1zg3ugvqkZB/Exq+usypIOwQVp1KL58TrjBRda0HvRctzkNhr0qYAtkfLFe0GvksBp4vBm8uGwAx7fw/HbhIjQ9pekTwvB+5GwDPO/tSip/1bQfCS+XJB8Ffa04HYPLGedalnWBrwhYY+G/kn5Zh9L/AC8xeLwTJTHM212rBjPa9CWs9C6a57MSaeGIEHLC1hEyiJJ15w8jmY=

See also

flatpak(1), flatpak-install(1) flatpak-flatpakrepo(5),
Name

flatpak-make-current — Make a specific version of an app current
Synopsis

flatpak make-current [OPTION...] APP BRANCH
Description

Makes a particular branch of an application current. Only the current branch of an app has its exported files (such as desktop files and icons) made visible to the host.

When a new branch is installed it will automatically be made current, so this command is often not needed.

Unless overridden with the --user option, this command creates a system-wide installation.
Options

The following options are understood:

-h, --help

    Show help options and exit. 
--user

    Create a per-user installation. 
--system

    Create a system-wide installation. 
--arch=ARCH

    The architecture to install for. 
-v, --verbose

    Print debug information during command processing. 
--version

    Print version information and exit. 

Examples

$ flatpak --user make-current org.gnome.GEdit 3.14
See also

flatpak(1), flatpak-install(1), flatpak-list(1) 
