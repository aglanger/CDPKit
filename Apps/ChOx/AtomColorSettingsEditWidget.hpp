/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * AtomColorSettingsEditWidget.hpp 
 *
 * This file is part of the Chemical Data Processing Toolkit
 *
 * Copyright (C) 2003-2020 Thomas A. Seidel <thomas.seidel@univie.ac.at>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; see the file COPYING. If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef CHOX_ATOMCOLORSETTINGSEDITWIDGET_HPP
#define CHOX_ATOMCOLORSETTINGSEDITWIDGET_HPP

#include "CDPL/Vis/ColorTable.hpp"

#include "SettingsEditWidget.hpp"


class QCheckBox;


namespace ChOx
{

	class Settings;

	class AtomColorSettingsEditWidget : public SettingsEditWidget
	{

		Q_OBJECT

	public:
		AtomColorSettingsEditWidget(QWidget*, Settings&);

		bool haveChangedSettings() const;

	signals:
		void updateGUI();

	public slots:
		void apply();
		void reset();
		void setDefaults();

	private slots:
		void handleSettingsChange();
		void handleSettingsChange(bool);

	private:
		void init();

		Settings&             settings;
		CDPL::Vis::ColorTable atomColors;
		CDPL::Vis::Color      defaultColor;
		QCheckBox*            enableColorTabCheckBox;
		QWidget*              colorTabWidget;
		bool                  haveChanges;
	};
}

#endif // CHOX_ATOMCOLORSETTINGSEDITWIDGET_HPP
