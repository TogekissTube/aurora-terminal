#include "include/about.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

About::About(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Acerca de");
    resize(400, 300);

    auto *layout = new QVBoxLayout(this);

    auto *label = new QLabel("Terminal for AuroraDE\n\n"
                             "Created by TogekissTube\n\n"
                             "Powered by Qt", this);
    label->setAlignment(Qt::AlignCenter);

    auto *closeButton = new QPushButton("Cerrar", this);
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);

    layout->addWidget(label);
    layout->addWidget(closeButton);
    setLayout(layout);
}
