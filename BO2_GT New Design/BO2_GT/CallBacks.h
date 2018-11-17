void ChangeColourValue(int which) //0 = Down, 1 = Up
{
	switch (which)
	{
	case 0:
		switch (RGBscroll)
		{
		case 0:
			RGBr--;
			if (RGBr < 0)
				RGBr = 255;
			break;
		case 1:
			RGBg--;
			if (RGBg < 0)
				RGBg = 255;
			break;
		case 2:
			RGBb--;
			if (RGBb < 0)
				RGBb = 255;
			break;
		case 3:
			RGBa--;
			if (RGBa < (0.2 * 255))
				RGBa = 255;
			break;
		}
		break;
	case 1:
		switch (RGBscroll)
		{
		case 0:
			RGBr++;
			if (RGBr > 255)
				RGBr = 0;
			break;
		case 1:
			RGBg++;
			if (RGBg > 255)
				RGBg = 0;
			break;
		case 2:
			RGBb++;
			if (RGBb > 255)
				RGBb = 0;
			break;
		case 3:
			RGBa++;
			if (RGBa > 255)
				RGBa = (0.2 * 255);
			break;
		}
		break;
	}
	RGBEditorCol.r = RGBr / 255;
	RGBEditorCol.g = RGBg / 255;
	RGBEditorCol.b = RGBb / 255;
	RGBEditorCol.a = RGBa / 255;
}

void SaveColour()
{
	switch (SubmenuScroll)
	{
	case 0:
		switch (scroll)
		{
		case 3:
			Smoke = RGBEditorCol;
			break;
		}
		break;
	case 8:
		switch (scroll)
		{
		case 0:
			Selector = RGBEditorCol;
			radarOutline = RGBEditorCol;
			rOutline = RGBEditorCol;
			break;
		case 1:
			ESPCrosshairCol = RGBEditorCol;
			break;
		}
		break;
	}
}

void comboBoxCallback()
{
	
		switch (SubmenuScroll)
		{
		case 2:
			switch (scroll)
			{
			case 2:
				BoxType = comboScroll;
				switch (comboScroll)
				{
				case 0:
					ESPBoxT = "None";
					break;
				case 1:
					ESPBoxT = "2D";
					break;
				case 2:
					ESPBoxT = "3D";
					break;
				case 3:
					ESPBoxT = "Triangle";
					break;
				case 4:
					ESPBoxT = "Corner";
					break;
				}
				break;
			case 7:
				SnapType = comboScroll;
				switch (comboScroll)
				{
				case 0:
					ESPSnapT = "None";
					break;
				case 1:
					ESPSnapT = "Top";
					break;
				case 2:
					ESPSnapT = "Middle";
					break;
				case 3:
					ESPSnapT = "Bottom";
					break;
				}
				break;
			}
			break;
		case 3:
			switch (scroll)
			{
			case 1:
				switch (comboScroll)
				{
				case 0:
					aimKey = "None";
					AimingRequired = false;
					break;
				case 1:
					aimKey = "L1";
					AimingRequired = true;
					AimingKey = 1;
					break;
				case 2:
					aimKey = "L2";
					AimingRequired = true;
					AimingKey = 2;
					break;
				case 3:
					aimKey = "R1";
					AimingRequired = true;
					AimingKey = 3;
					break;
				case 4:
					aimKey = "R2";
					AimingRequired = true;
					AimingKey = 4;
					break;
				}
				break;
			case 2:
				switch (comboScroll)
				{
				case 0:
					aimType = "Regular";
					sAimbot = false;
					break;
				case 1:
					aimType = "Silent";
					sAimbot = true;
					break;
				}
				break;
			case 3:
				switch (comboScroll)
				{
				case 0:
					targType = "Closest";
					Stealth = false;
					Logical = false;
					break;
				case 1:
					targType = "Logical";
					Stealth = false;
					Logical = true;
					break;
				case 2:
					targType = "Visible Only";
					Stealth = true;
					Logical = false;
					break;
				}
				break;
			case 8:
				switch (comboScroll)
				{
				case 0:
					riotCheck = "Regular";
					ignoreShields = 0;
					break;
				case 1:
					riotCheck = "Feet";
					ignoreShields = 2;
					break;
				}
				break;
			}
			break;
		case 4:
			switch (scroll)
			{
			case 1:
				xAntiAimType = comboScroll;
				switch (comboScroll)
				{
				case 0:
					xAntiAim = "None";

					break;
				case 1:
					xAntiAim = "Emotion";
					break;
				case 2:
					xAntiAim = "Up";
					break;
				case 3:
					xAntiAim = "Down";
					break;
				case 4:
					xAntiAim = "Invert on Shoot";
					break;
				case 5:
					xAntiAim = "AimAngles";
					break;
				}
				break;
			case 2:
				yAntiAimType = comboScroll;
				switch (comboScroll)
				{
				case 0:
					yAntiAim = "None";
					break;
				case 1:
					yAntiAim = "Jitter";
					break;
				case 2:
					yAntiAim = "Spin Bot";
					break;
				case 3:
					yAntiAim = "Shield";
					break;
				case 4:
					yAntiAim = "Invert on Shoot";
					break;
				case 5:
					yAntiAim = "Body to Enemy";
					break;
				case 6:
					yAntiAim = "Shield to Enemy";
					break;
				}
				break;
			}
			break;
		case 5:
			switch (scroll)
			{
			case 6:
				CrossType = comboScroll;
				switch (comboScroll)
				{
				case 0:
					CrossHair = "Disable";
					break;
				case 1:
					CrossHair = "+";
					break;
				case 2:
					CrossHair = "X";
					break;
				}
				break;
			}
			break;
		case 6:
			switch (scroll)
			{
			case 1:
				switch (comboScroll)
				{
				case 0:
					SpoofedIP = "Spoofing Disabled";
					ChangeIP(4);
					break;
				case 1:
					SpoofedIP = "0.0.0.0";
					ChangeIP(1);
					break;
				case 2:
					SpoofedIP = "1.3.3.7";
					ChangeIP(0);
					break;
				case 3:
					SpoofedIP = "255.255.255.255";
					ChangeIP(2);
					break;
				}
				break;
				
			}
			break;
		}
	/*
	else
	{
		switch (PreSubmenuScroll)
		{
		case 2:
			switch (PreScroll)
			{
			case 3:
				switch (comboScroll)
				{
				case 0:
					SpoofedIP = "Spoofing Disabled";
					ChangeIP(4);
					break;
				case 1:
					SpoofedIP = "0.0.0.0";
					ChangeIP(1);
					break;
				case 2:
					SpoofedIP = "1.3.3.7";
					ChangeIP(0);
					break;
				case 3:
					SpoofedIP = "255.255.255.255";
					ChangeIP(2);
					break;
				}
				break;
			}
		}
	}*/
	comboBoxOpen = false;
}

void comboBoxCallbackZM()
{
	if (InGame)
	{
		switch (SubmenuScroll)
		{
		case 1:
			switch (scroll)
			{
			case 3:
				BoxType = comboScroll;
				switch (comboScroll)
				{
				case 0:
					ESPBoxT = "None";
					break;
				case 1:
					ESPBoxT = "2D";
					break;
				case 2:
					ESPBoxT = "3D";
					break;
				case 3:
					ESPBoxT = "Triangle";
					break;
				case 4:
					ESPBoxT = "Corner";
					break;
				}
				break;
			case 4:
				SnapType = comboScroll;
				switch (comboScroll)
				{
				case 0:
					ESPSnapT = "None";
					break;
				case 1:
					ESPSnapT = "Top";
					break;
				case 2:
					ESPSnapT = "Middle";
					break;
				case 3:
					ESPSnapT = "Bottom";
					break;
				}
				break;
			}
			break;
		case 2:
			switch (scroll)
			{
			case 1:
				switch (comboScroll)
				{
				case 0:
					aimKey = "None";
					AimingRequired = false;
					break;
				case 1:
					aimKey = "L1";
					AimingRequired = true;
					AimingKey = 1;
					break;
				case 2:
					aimKey = "L2";
					AimingRequired = true;
					AimingKey = 2;
					break;
				case 3:
					aimKey = "R1";
					AimingRequired = true;
					AimingKey = 3;
					break;
				case 4:
					aimKey = "R2";
					AimingRequired = true;
					AimingKey = 4;
					break;
				}
				break;
			case 2:
				switch (comboScroll)
				{
				case 0:
					aimType = "Regular";
					sAimbot = false;
					break;
				case 1:
					aimType = "Silent";
					sAimbot = true;
					break;
				}
				break;
			case 3:
				switch (comboScroll)
				{
				case 0:
					targType = "Closest";
					Stealth = false;
					Logical = false;
					break;
				case 1:
					targType = "Logical";
					Stealth = false;
					Logical = true;
					break;
				case 2:
					targType = "Visible Only";
					Stealth = true;
					Logical = false;
					break;
				}
				break;
			case 8:
				switch (comboScroll)
				{
				case 0:
					riotCheck = "Regular";
					ignoreShields = 0;
					break;
				case 1:
					riotCheck = "Feet";
					ignoreShields = 2;
					break;
				}
				break;
			}
			break;
		case 3:
			switch (scroll)
			{
			case 1:
				xAntiAimType = comboScroll;
				switch (comboScroll)
				{
				case 0:
					xAntiAim = "None";
					break;
				case 1:
					xAntiAim = "Emotion";
					break;
				case 2:
					xAntiAim = "Up";
					break;
				case 3:
					xAntiAim = "Down";
					break;
				case 4:
					xAntiAim = "Invert on Shoot";
					break;
				case 5:
					xAntiAim = "AimAngles";
					break;
				}
				break;
			case 2:
				yAntiAimType = comboScroll;
				switch (comboScroll)
				{
				case 0:
					yAntiAim = "None";
					break;
				case 1:
					yAntiAim = "Jitter";
					break;
				case 2:
					yAntiAim = "Spin Bot";
					break;
				case 3:
					yAntiAim = "Shield";
					break;
				case 4:
					yAntiAim = "Invert on Shoot";
					break;
				case 5:
					yAntiAim = "Body to Enemy";
					break;
				case 6:
					yAntiAim = "Shield to Enemy";
					break;
				}
				break;
			}
			break;
		}
	}
	else
	{
		switch (PreSubmenuScroll)
		{
		case 2:
			switch (PreScroll)
			{
			case 3:
				switch (comboScroll)
				{
				case 0:
					SpoofedIP = "Spoofing Disabled";
					ChangeIP(4);
					break;
				case 1:
					SpoofedIP = "0.0.0.0";
					ChangeIP(1);
					break;
				case 2:
					SpoofedIP = "1.3.3.7";
					ChangeIP(0);
					break;
				case 3:
					SpoofedIP = "255.255.255.255";
					ChangeIP(2);
					break;
				}
				break;
			}
		}
	}
	comboBoxOpen = false;
}

int currComboOpt;
char* currBox;
int currBoxInt;
void comboBox(int aop)
{
	comboBoxOpen = true;
	comboScroll = 0;
	maxComboScroll = aop - 1;
}