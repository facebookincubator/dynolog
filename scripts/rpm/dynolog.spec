Name:           dynolog
Version:        __VERSION__
Release:        1%{?dist}
Summary:        A system monitoring and profiling daemon.

License:        MIT
URL:            https://github.com/facebookincubator/dynolog
Source0:        %{name}-%{version}.tar.gz

BuildRequires: systemd-rpm-macros

%global debug_package %{nil}
%define _mybindir /usr/local/bin

%description
Dynolog is an observability daemon for system monitoring and profiling.
* It support telemetry on heterogenous CPU/GPU platforms.
* Integrates with pytorch and can trigger traces for distributed training applications.

%prep
%autosetup

%post
%systemd_post dynolog.service

%preun
%systemd_preun dynolog.service

%postun
%systemd_postun_with_restart dynolog.service

# perc build
# perc configure
# perc make_build

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{_mybindir}
mkdir -p $RPM_BUILD_ROOT/%{_unitdir}
cp dynomin $RPM_BUILD_ROOT/%{_mybindir}
cp dyno2 $RPM_BUILD_ROOT/%{_mybindir}
cp dynolog.service $RPM_BUILD_ROOT/%{_unitdir}

%files
# perc license add-license-file-here
# perc doc add-docs-here
%{_mybindir}/dynomin
%{_mybindir}/dyno2
%{_unitdir}/dynolog.service

%changelog
* Wed Jun 15 2022 briancoutinho <bcoutinho@meta.com> added v0.0.1 with system perf monitoring capabilities.
- 
