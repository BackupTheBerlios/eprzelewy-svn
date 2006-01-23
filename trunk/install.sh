#!/bin/bash

install -m 755 ./bin/eprzelewy /usr/bin

mkdir -p /usr/share/eprzelewy
mkdir -p /usr/share/eprzelewy/icons
install -c -p -m 644 ./share/eprzelewy/icons/dane_firmy.png /usr/share/eprzelewy/icons/dane_firmy.png
install -c -p -m 644 ./share/eprzelewy/icons/dodaj_kontrahentow.png /usr/share/eprzelewy/icons/dodaj_kontrahentow.png
install -c -p -m 644 ./share/eprzelewy/icons/edytuj_kontrahentow.png /usr/share/eprzelewy/icons/edytuj_kontrahentow.png
install -c -p -m 644 ./share/eprzelewy/icons/edytuj_przelew.png /usr/share/eprzelewy/icons/edytuj_przelew.png
install -c -p -m 644 ./share/eprzelewy/icons/eprzelewy_128.png /usr/share/eprzelewy/icons/eprzelewy_128.png
install -c -p -m 644 ./share/eprzelewy/icons/eprzelewy_16.png /usr/share/eprzelewy/icons/eprzelewy_16.png
install -c -p -m 644 ./share/eprzelewy/icons/eprzelewy_32.png /usr/share/eprzelewy/icons/eprzelewy_32.png
install -c -p -m 644 ./share/eprzelewy/icons/eprzelewy_48.png /usr/share/eprzelewy/icons/eprzelewy_48.png
install -c -p -m 644 ./share/eprzelewy/icons/eprzelewy_64.png /usr/share/eprzelewy/icons/eprzelewy_64.png
install -c -p -m 644 ./share/eprzelewy/icons/k2.png /usr/share/eprzelewy/icons/k2.png
install -c -p -m 644 ./share/eprzelewy/icons/koniec.png /usr/share/eprzelewy/icons/koniec.png
install -c -p -m 644 ./share/eprzelewy/icons/kreator.png /usr/share/eprzelewy/icons/kreator.png
install -c -p -m 644 ./share/eprzelewy/icons/nowy_przelew.png /usr/share/eprzelewy/icons/nowy_przelew.png
install -c -p -m 644 ./share/eprzelewy/icons/nowy_przelew_us.png /usr/share/eprzelewy/icons/nowy_przelew_us.png
install -c -p -m 644 ./share/eprzelewy/icons/nowy_przelew_zus.png /usr/share/eprzelewy/icons/nowy_przelew_zus.png
install -c -p -m 644 ./share/eprzelewy/icons/o_programie.png /usr/share/eprzelewy/icons/o_programie.png
install -c -p -m 644 ./share/eprzelewy/icons/splash.png /usr/share/eprzelewy/icons/splash.png
install -c -p -m 644 ./share/eprzelewy/icons/ustawienia.png /usr/share/eprzelewy/icons/ustawienia.png
install -c -p -m 644 ./share/eprzelewy/icons/usun_kontrahentow.png /usr/share/eprzelewy/icons/usun_kontrahentow.png
install -c -p -m 644 ./share/eprzelewy/icons/usun_przelew.png /usr/share/eprzelewy/icons/usun_przelew.png

mkdir -p /usr/share/eprzelewy/druki
install -c -p -m 644 ./share/eprzelewy/druki/standard.png /usr/share/eprzelewy/druki/standard.png
install -c -p -m 644 ./share/eprzelewy/druki/zus.png /usr/share/eprzelewy/druki/zus.png
install -c -p -m 644 ./share/eprzelewy/druki/us.png /usr/share/eprzelewy/druki/us.png

mkdir -p /usr/share/applications
install -c -p  -m 644 ./share/eprzelewy/icons/eprzelewy.desktop /usr/share/applications/eprzelewy.desktop 

mkdir -p /usr/share/applications/kde
install -c -p  -m 644 ./share/eprzelewy/icons/eprzelewy.desktop /usr/share/applications/kde/eprzelewy.desktop