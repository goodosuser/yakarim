#ifndef YAKARIMMAINWINDOW_H
#define YAKARIMMAINWINDOW_H

#include <QtWidgets>

class QWebView;
QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

//! [1]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QUrl& url);
    // this event is called, when a new translator is loaded or the system language is changed
    void changeEvent(QEvent*);

protected slots:
    // this slot is called by the language menu actions
    void slotLanguageChanged(QAction* action);

    void adjustLocation();
    void changeLocation();
    void adjustTitle();
    void setProgress(int p);
    void finishLoading(bool);

    void viewSource();
    void slotSourceDownloaded();


private:
    // loads a language by the given language shortcur (e.g. de, en)
    void loadLanguage(const QString& rLanguage);

    // creates the language menu dynamically from the content of m_langPath
    void createLanguageMenu(void);

    QTranslator m_translator; // contains the translations for this application
    QTranslator m_translatorQt; // contains the translations for qt
    QString m_currLang; // contains the currently loaded language
    QString m_langPath; // Path of language files. This is always fixed to /languages.

    QWebView *view;
    QLineEdit *locationEdit;

    int progress;
//! [1]
};

#endif
// YAKARIMMAINWINDOW_H

/*from fanncy sample
#include <QtWidgets>

class QWebView;
QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

//! [1]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QUrl& url);

protected slots:

    void adjustLocation();
    void changeLocation();
    void adjustTitle();
    void setProgress(int p);
    void finishLoading(bool);

    void viewSource();
    void slotSourceDownloaded();

    void highlightAllLinks();
    void rotateImages(bool invert);
    void removeGifImages();
    void removeInlineFrames();
    void removeObjectElements();
    void removeEmbeddedElements();

private:
    QString jQuery;
    QWebView *view;
    QLineEdit *locationEdit;
    QAction *rotateAction;
    int progress;
//! [1]
};

 **/
